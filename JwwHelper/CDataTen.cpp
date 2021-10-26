#include "pch.h"
#include "CDataTen.h"

IMPLEMENT_SERIAL(CDataTen, CData, JWW_VERSION | VERSIONABLE_SCHEMA);

void CDataTen::Serialize(CArchive& ar)
{
	CData::Serialize(ar);
	if (ar.IsStoring()) {
		ar << (double)m_start_x << (double)m_start_y;
		ar << (DWORD)m_bKariten;
		if (100 == m_nPenStyle) {
			ar << (DWORD)m_nCode;
			ar << (double)m_radKaitenKaku;
			ar << (double)m_dBairitsu;
		}
	}
	else {
		ar >> m_start_x >> m_start_y;
		ar >> m_bKariten;
		if (100 == m_nPenStyle) {
			ar >> m_nCode;
			ar >> m_radKaitenKaku;
			ar >> m_dBairitsu;
		}
	}
}
