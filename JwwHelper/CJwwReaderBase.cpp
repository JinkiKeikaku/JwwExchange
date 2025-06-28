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

void CJwwReaderBase::Read(CArchive& ar) {
	m_DataList.RemoveAll();
	ReadFileType(ar);
	ReadHeader(ar);
	ReadData(ar);
	ReadDataList(ar);
	ReadImages(ar);
}


void CJwwReaderBase::Read(LPCTSTR path) {
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CFile file;
	file.Open(path, CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	try {
		Read(ar);
	}
	finally {
		ar.Close();
	}
}

void CJwwReaderBase::Read(byte* buf, int size) {
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CMemFile file(buf, size);
	CArchive ar(&file, CArchive::load);
	try {
		Read(ar);
	}
	finally {
		ar.Close();
	}
}



void CJwwReaderBase::ReadData(CArchive& ar) {
	m_DataList.Serialize(ar);
}

void CJwwReaderBase::ReadDataList(CArchive& ar) {
	m_DataListList.Serialize(ar);
}

