#include "pch.h"
#include "JwwWriter.h"

namespace JwwHelper {
	JwwWriter::JwwWriter() {
		m_pWriter = new CJwwWriter();
		_Header = gcnew JwwHeader(m_pWriter->m_pHeader->Clone());
	}
	JwwWriter::~JwwWriter() {
		this->!JwwWriter();
	}
	JwwWriter::!JwwWriter() {
		delete m_pWriter;
	}

	void JwwWriter::InitHeader(String^ templatePath) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		pin_ptr<const WCHAR> str = PtrToStringChars(templatePath);
		CW2A astr(str);
		//�t�@�C����ǂݍ���Ńw�b�_�[��������
		m_pWriter->InitHeader(astr);
		//C#������w�b�_�[��ύX�ł���悤�ɃR�s�[�B�R�s�[�ł��邱�Ƃɒ��ӁB
		_Header = gcnew JwwHeader(m_pWriter->m_pHeader->Clone());
	}

	void JwwWriter::AddData(JwwData^ data) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		m_pWriter->m_DataList.AddTail(data->Clone());
	}
	void JwwWriter::AddDataList(JwwDataList^ dataList) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		m_pWriter->m_DataListList.AddTail((CDataList*)dataList->Clone());
	}
	void JwwWriter::AddImage(JwwImage^ image) {
		m_pWriter->m_Images.push_back(image->m_pImage->Clone());
	}

	void JwwWriter::Write(String^ path) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		pin_ptr<const WCHAR> str = PtrToStringChars(path);
		CW2A astr(str);
		//C#���w�b�_�[��C++����������
		m_pWriter->InitHeader(_Header->GetNativeHeader());
		//for (int i = 0; i < mImages->Length; i++) {
		//	CJwwImage* ji = mImages[i]->m_pImage->Clone();
		//	m_pWriter->m_Images.push_back(ji);
		//}
		m_pWriter->Write(astr);
	}
}