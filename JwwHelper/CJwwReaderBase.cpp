#include "pch.h"
#include "CJwwReaderBase.h"
#include "CDataList.h"

CJwwReaderBase::CJwwReaderBase() {
}

CJwwReaderBase::~CJwwReaderBase() {

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

void CJwwReaderBase::Read(LPCTSTR path) {
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_DataList.RemoveAll();
	CFile file;
	file.Open(path, CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	try {
		ReadFileType(ar);
		ReadHeader(ar);
		ReadData(ar);
		ReadDataList(ar);
		ReadImages(ar);
		ar.Close();
	}
	catch (...) {
		ar.Close();
		throw;
	}
}
void CJwwReaderBase::ReadData(CArchive& ar) {
	m_DataList.Serialize(ar);
}

void CJwwReaderBase::ReadDataList(CArchive& ar) {
	m_DataListList.Serialize(ar);
}

