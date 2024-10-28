#include "pch.h"
#include "JwwClipReader.h"
#include "JwwData.h"

namespace JwwHelper {

	void JwwClipReader::Read(array<byte>^ buffer, CompletedCallback^ completed)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		pin_ptr<byte> pinned = &buffer[0];
		m_pReader->Read((byte*)pinned, buffer->Length);
		ConvertToManaged();
		if (completed != nullptr) {
			completed(this);
		}
	}
	void JwwClipReader::ConvertToManaged() {
		mHeader = gcnew JwwClipHeader(m_pReader->m_pHeader->Clone());
		mDataList->Clear();
		POSITION pos = m_pReader->m_DataList.GetHeadPosition();
		while (pos != NULL) {
			CData* data = m_pReader->m_DataList.GetNext(pos);
			JwwData^ jd = ConvertToJwwData(data);
			if (jd != nullptr) mDataList->Add(jd);
		}
		pos = m_pReader->m_DataListList.GetHeadPosition();
		while (pos != NULL) {
			CDataList* data = m_pReader->m_DataListList.GetNext(pos);
			mDataListList->Add(gcnew JwwDataList((CDataList*)data->Clone()));
		}
	}
}
