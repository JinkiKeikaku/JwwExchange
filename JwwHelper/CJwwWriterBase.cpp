#include "CJwwWriterBase.h"

CJwwWriterBase::CJwwWriterBase() {
}

CJwwWriterBase::~CJwwWriterBase() {
	{
		POSITION pos = m_DataList.GetHeadPosition();
		while (pos != NULL) {
			CData* data = m_DataList.GetNext(pos);
			delete data;
		}
	}
	{
		POSITION pos = m_DataListList.GetHeadPosition();
		while (pos != NULL) {
			CDataList* data = m_DataListList.GetNext(pos);
			delete data;
		}
	}
}

void CJwwWriterBase::Write(LPCTSTR path) {
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CFile file;
	file.Open(path, CFile::modeWrite | CFile::modeCreate);
	CArchive ar(&file, CArchive::store);
	WriteFileType(ar);
	WriteHeader(ar);
	WriteData(ar);
	WriteDataList(ar);
	WriteImages(ar);
	ar.Close();
}

void CJwwWriterBase::WriteData(CArchive& ar) {
	m_DataList.Serialize(ar);
}
void CJwwWriterBase::WriteDataList(CArchive& ar) {
	m_DataListList.Serialize(ar);
}

