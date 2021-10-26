#include "pch.h"
#include "CDataSolid.h"

IMPLEMENT_SERIAL(CDataSolid, CData, JWW_VERSION | VERSIONABLE_SCHEMA);

void CDataSolid::Serialize(CArchive& ar)
{
	CData::Serialize(ar);
	if (ar.IsStoring()) {
		ar << (double)m_start_x << (double)m_start_y
			<< (double)m_end_x << (double)m_end_y
			<< (double)m_DPoint2_x << (double)m_DPoint2_y
			<< (double)m_DPoint3_x << (double)m_DPoint3_y;
		if (10 == m_nPenColor) {
			ar << (DWORD)m_Color;//RGB
		}
	}
	else {
		ar >> (double)m_start_x >> (double)m_start_y
			>> (double)m_end_x >> (double)m_end_y
			>> (double)m_DPoint2_x >> (double)m_DPoint2_y
			>> (double)m_DPoint3_x >> (double)m_DPoint3_y;
		if (10 == m_nPenColor) {
			ar >> (DWORD)m_Color;//RGB
		}
	}
}
