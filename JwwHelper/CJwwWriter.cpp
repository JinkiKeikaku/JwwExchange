#include "pch.h"
#include "CJwwWriter.h"
#include "CJwwReader.h"

CJwwWriter::CJwwWriter() {
	m_pHeader = new CJwwHeader();
}

CJwwWriter::~CJwwWriter() {
	delete m_pHeader;
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
	for (size_t i = 0; i < m_Images.size(); i++) {
		delete m_Images[i];
	}
}

void CJwwWriter::Write(LPCTSTR path) {
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CFile file;
	file.Open(path, CFile::modeWrite | CFile::modeCreate);
	CArchive ar(&file, CArchive::store);
	BYTE buf[8];
	memcpy(buf, "JwwData.", 8);
	ar.Write(buf, 8);
	WriteHeader(ar);
	WriteData(ar);
	WriteDataList(ar);
	WriteImage(ar);
	ar.Close();
}

void CJwwWriter::InitHeader(LPCTSTR path) {
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CFile file;
	file.Open(path, CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	BYTE buf[8];
	ar.Read(buf, 8);
	if (memcmp(buf, "JwwData.", 8) != 0)	AfxThrowFileException(CFileException::invalidFile);
	m_pHeader->Read(ar);
	ar.Close();
}

void CJwwWriter::InitHeader(CJwwHeader* pHeader) {
	delete m_pHeader;
	m_pHeader = pHeader->Clone();
}


void CJwwWriter::WriteHeader(CArchive& ar) {
	m_pHeader->Write(ar);
}

void CJwwWriter::WriteData(CArchive& ar) {
	m_DataList.Serialize(ar);
}
void CJwwWriter::WriteDataList(CArchive& ar) {
	m_DataListList.Serialize(ar);
}

void CJwwWriter::WriteImage(CArchive& ar) {
	ar << (UINT)m_Images.size();
	for(size_t i = 0; i < m_Images.size(); i++){
		CJwwImage* p = m_Images[i];
		ar << p->m_ImageName;
		ar << (UINT)p->m_Size;
		ar.Write(p->m_pBuffer, p->m_Size);
	}
}

