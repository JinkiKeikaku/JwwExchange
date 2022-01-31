#include "JwsWriter.h"

namespace JwwHelper {
	JwsWriter::JwsWriter() {
		m_pWriter = new CJwsWriter();
		_Header = gcnew JwsHeader(m_pWriter->m_pHeader->Clone());
	}
	JwsWriter::~JwsWriter() {
		this->!JwsWriter();
	}
	JwsWriter::!JwsWriter() {
		delete m_pWriter;
	}

	void JwsWriter::AddData(JwwData^ data) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		m_pWriter->m_DataList.AddTail(data->Clone());
	}
	void JwsWriter::AddDataList(JwwDataList^ dataList) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		m_pWriter->m_DataListList.AddTail((CDataList*)dataList->Clone());
	}

	void JwsWriter::Write(String^ path) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		pin_ptr<const WCHAR> str = PtrToStringChars(path);
		CW2A astr(str);
		m_pWriter->InitHeader(_Header->GetNativeHeader());
		m_pWriter->Write(astr);
	}

}