#include "pch.h"
#include "CJwwReader.h"

CJwwReader::CJwwReader() : CJwwReaderBase() {
	m_pHeader = new CJwwHeader();
}
CJwwReader::~CJwwReader() {
	delete m_pHeader;
	for (size_t i = 0; i < m_Images.size(); i++) {
		delete m_Images[i];
	}
}

void CJwwReader::ReadFileType(CArchive& ar) {
	BYTE buf[8];
	ar.Read(buf, 8);
	if (memcmp(buf, "JwwData.", 8) != 0) {
		AfxThrowFileException(CFileException::invalidFile);
	}
}

void CJwwReader::ReadHeader(CArchive& ar) {
	m_pHeader->Read(ar);
}


void CJwwReader::ReadImages(CArchive& ar) {
	if (m_pHeader->m_jwwDataVersion < 700) return;
	int nImage;
	ar >> nImage;
	for (int i = 0; i < nImage; i++) {
		int size;
		CString name;
		ar >> name;
		ar >> size;
		BYTE* pBuffer = new BYTE[size];
		ar.Read(pBuffer, size);
		CJwwImage* data = new CJwwImage(name, pBuffer, size);
		m_Images.push_back(data);
	}
}

