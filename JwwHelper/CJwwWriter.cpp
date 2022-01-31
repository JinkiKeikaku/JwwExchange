#include "pch.h"
#include "CJwwWriter.h"
#include "CJwwReader.h"

CJwwWriter::CJwwWriter() {
	m_pHeader = new CJwwHeader();
}

CJwwWriter::~CJwwWriter() {
	delete m_pHeader;
	for (size_t i = 0; i < m_Images.size(); i++) {
		delete m_Images[i];
	}
}

void CJwwWriter::WriteFileType(CArchive& ar) {
	BYTE buf[8];
	memcpy(buf, "JwwData.", 8);
	ar.Write(buf, 8);
}

void CJwwWriter::WriteHeader(CArchive& ar) {
	m_pHeader->Write(ar);
}


void CJwwWriter::WriteImages(CArchive& ar) {
	ar << (UINT)m_Images.size();
	for (size_t i = 0; i < m_Images.size(); i++) {
		CJwwImage* p = m_Images[i];
		ar << p->m_ImageName;
		ar << (UINT)p->m_Size;
		ar.Write(p->m_pBuffer, p->m_Size);
	}
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



