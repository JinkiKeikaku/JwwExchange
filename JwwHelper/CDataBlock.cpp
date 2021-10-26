#include "pch.h"
#include "CDataBlock.h"
#include "CJwwHeader.h"

IMPLEMENT_SERIAL(CDataBlock, CData, JWW_VERSION | VERSIONABLE_SCHEMA);
void CDataBlock::Serialize(CArchive& ar) {
	CData::Serialize(ar);
	if (ar.IsStoring()) {
		ar << (double)m_DPKijunTen_x << (double)m_DPKijunTen_y
			<< (double)m_dBairitsuX
			<< (double)m_dBairitsuY
			<< (double)m_radKaitenKaku
			<< (DWORD)m_nNumber;
	}
	else {
		ar >> (double)m_DPKijunTen_x >> (double)m_DPKijunTen_y
			>> (double)m_dBairitsuX
			>> (double)m_dBairitsuY
			>> (double)m_radKaitenKaku
			>> (DWORD)m_nNumber;
	}
}

