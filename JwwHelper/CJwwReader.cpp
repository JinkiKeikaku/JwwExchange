#include "pch.h"
#include "CJwwReader.h"

CJwwReader::CJwwReader(LPCTSTR temporaryFolder) : CJwwReaderBase(temporaryFolder) {
	m_pHeader = new CJwwHeader();
}
CJwwReader::~CJwwReader() {
	delete m_pHeader;
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
