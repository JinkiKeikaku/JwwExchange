#include "CJwwClipWriter.h"

CJwwClipWriter::CJwwClipWriter() {
	m_pHeader = new CJwwClipHeader();
}

CJwwClipWriter::~CJwwClipWriter() {
	delete m_pHeader;
}

void CJwwClipWriter::WriteFileType(CArchive& ar) {
}

void CJwwClipWriter::WriteHeader(CArchive& ar) {
	m_pHeader->Write(ar);
}

void CJwwClipWriter::InitHeader(CJwwClipHeader* pHeader) {
	delete m_pHeader;
	m_pHeader = pHeader->Clone();
}
