#include "JwwClipWriter.h"

namespace JwwHelper {
	JwwClipWriter::JwwClipWriter() {
		m_pWriter = new CJwwClipWriter();
		_Header = gcnew JwwClipHeader(m_pWriter->m_pHeader->Clone());
	}
	JwwClipWriter::~JwwClipWriter() {
		this->!JwwClipWriter();
	}
	JwwClipWriter::!JwwClipWriter() {
		delete m_pWriter;
	}

	void JwwClipWriter::AddData(JwwData^ data) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		m_pWriter->m_DataList.AddTail(data->Clone());
	}
	void JwwClipWriter::AddDataList(JwwDataList^ dataList) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		m_pWriter->m_DataListList.AddTail((CDataList*)dataList->Clone());
	}

	IntPtr JwwClipWriter::Write() {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		m_pWriter->InitHeader(_Header->GetNativeHeader());
		return IntPtr(m_pWriter->WriteToMemory());
	}

}