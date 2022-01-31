#include "pch.h"
#include "CJwsWriter.h"

CJwsWriter::CJwsWriter() {
	m_pHeader = new CJwsHeader();
}

CJwsWriter::~CJwsWriter() {
	delete m_pHeader;
}

void CJwsWriter::WriteFileType(CArchive& ar) {
	BYTE buf[8];
	memcpy(buf, "JwsData.", 8);
	ar.Write(buf, 8);
}

void CJwsWriter::WriteHeader(CArchive& ar) {
	m_pHeader->Write(ar);
}

void CJwsWriter::InitHeader(CJwsHeader* pHeader) {
	delete m_pHeader;
	m_pHeader = pHeader->Clone();
}
