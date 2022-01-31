#include "pch.h"
#include "CJwsReader.h"


CJwsReader::CJwsReader() : CJwwReaderBase() {
	m_pHeader = new CJwsHeader();
}
CJwsReader::~CJwsReader() {
	delete m_pHeader;
}



void CJwsReader::ReadFileType(CArchive& ar) {
	BYTE buf[8];
	ar.Read(buf, 8);
	if (memcmp(buf, "JwsData.", 8) != 0) {
		AfxThrowFileException(CFileException::invalidFile);
	}
}


void CJwsReader::ReadHeader(CArchive& ar) {
	m_pHeader->Read(ar);
}

