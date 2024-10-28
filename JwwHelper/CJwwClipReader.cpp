#include "pch.h"
#include "CJwwClipReader.h"

CJwwClipReader::CJwwClipReader() : CJwwReaderBase() {
	m_pHeader = new CJwwClipHeader();
}

CJwwClipReader::~CJwwClipReader() {
	delete m_pHeader;
}


void CJwwClipReader::ReadFileType(CArchive& ar) {
}

void CJwwClipReader::ReadHeader(CArchive& ar) {
	m_pHeader->Read(ar);
}

