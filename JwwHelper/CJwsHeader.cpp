#include "pch.h"
#include "CJwsHeader.h"
#include "CData.h"

CJwsHeader::CJwsHeader() {
	for (int i = 0; i < 16; i++) {
		m_Scales[i] = 1.0;
	}
	//これが何者かわからない。
	for (int i = 0; i < 6; i++) {
		m_Tmp1[i] = i + 1;
		m_Tmp2[i] = i + 1;
	}
}

CJwsHeader::~CJwsHeader() {
}

void CJwsHeader::Read(CArchive& ar) {
	BYTE tmp[192];
	ar.Read(tmp, 192);
	ar >> m_jwsDataVersion;
	CData::s_FileVersion = m_jwsDataVersion;
	ar >> m_Origin_x >> m_Origin_y;
	for (int i = 0; i < 16; i++) {
		ar >> m_Scales[i];
	}
	for (int i = 0; i < 6; i++) {
		ar >> m_Tmp1[i];
	}
	for (int i = 0; i < 6; i++) {
		ar >> m_Tmp2[i];
	}
	ar >> m_Bounds_Left >> m_Bounds_Bottom >> m_Bounds_Right >> m_Bounds_Top;
}

void CJwsHeader::Write(CArchive& ar) {
	//ファイルを見ると192バイト0x2Eがあるので再現。意味は分からない。
	BYTE tmp[192];
	memset(tmp, 0x2E, 192);
	ar.Write(tmp, 192);
	ar << m_jwsDataVersion;
	ar << m_Origin_x << m_Origin_y;
	for (int i = 0; i < 16; i++) {
		ar << m_Scales[i];
	}
	for (int i = 0; i < 6; i++) {
		ar << m_Tmp1[i];
	}
	for (int i = 0; i < 6; i++) {
		ar << m_Tmp2[i];
	}
	ar << m_Bounds_Left << m_Bounds_Bottom << m_Bounds_Right << m_Bounds_Top;
}



CJwsHeader* CJwsHeader::Clone() {
	CMemFile mem;
	CArchive store(&mem, CArchive::store);
	Write(store);
	store.Close();
	DWORD len = mem.GetLength();
	BYTE* buf = mem.Detach();
	mem.Close();
	CMemFile tmp(buf, len);
	CArchive load(&tmp, CArchive::load);
	CJwsHeader* h = new CJwsHeader();
	h->Read(load);
	load.Close();
	tmp.Close();
	free(buf);
	return h;
}

