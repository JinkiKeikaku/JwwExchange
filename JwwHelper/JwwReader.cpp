#include "pch.h"
#include "JwwReader.h"
#include "JwwData.h"
#include "JwwSen.h"
#include "JwwMoji.h"
#include "JwwEnko.h"
#include "JwwTen.h"
#include "JwwSolid.h"
#include "JwwSunpou.h"
#include "JwwBlock.h"
#include "JwwUtility.h"

namespace JwwHelper {
	void JwwReader::Read(String^ path) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		pin_ptr<const WCHAR> str = PtrToStringChars(path);
		CW2A astr(str);

		m_pReader->Read(astr);
		ConvertToManaged();
		if (m_Completed != nullptr) {
			m_Completed(this);
		}
	}
	void JwwReader::ConvertToManaged() {
		mHeader = gcnew JwwHeader(m_pReader->m_pHeader->Clone());
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