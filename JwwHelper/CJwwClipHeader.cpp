#include "CJwwClipHeader.h"

CJwwClipHeader::CJwwClipHeader() {
	for (int i = 0; i < 16; i++) {
		m_Scales[i] = 1.0;
	}
}

CJwwClipHeader::~CJwwClipHeader() {
}

void CJwwClipHeader::Read(CArchive& ar) {
	ar >> m_Origin_x >> m_Origin_y;
	for (int i = 0; i < 16; i++) {
		ar >> m_Scales[i];
	}
}

void CJwwClipHeader::Write(CArchive& ar) {
	ar << m_Origin_x << m_Origin_y;
	for (int i = 0; i < 16; i++) {
		ar << m_Scales[i];
	}
}

CJwwClipHeader* CJwwClipHeader::Clone() {
	CMemFile mem;
	CArchive store(&mem, CArchive::store);
	Write(store);
	store.Close();
	DWORD len = mem.GetLength();
	BYTE* buf = mem.Detach();
	mem.Close();
	CMemFile tmp(buf, len);
	CArchive load(&tmp, CArchive::load);
	CJwwClipHeader* h = new CJwwClipHeader();
	h->Read(load);
	load.Close();
	tmp.Close();
	free(buf);
	return h;
}

