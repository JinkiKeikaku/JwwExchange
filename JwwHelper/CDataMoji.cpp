#include "pch.h"
#include "CDataMoji.h"

IMPLEMENT_SERIAL(CDataMoji, CData, JWW_VERSION | VERSIONABLE_SCHEMA);

CDataMoji::CDataMoji(){
	m_start_x = 0;
	m_start_y = 0;
	m_end_x = 0;
	m_end_y = 0;
	m_nMojiShu = 0;
	m_dSizeX = 4;
	m_dSizeY = 4;
	m_dKankaku = 0;
	m_degKakudo = 0;
}

void CDataMoji::Serialize(CArchive& ar) {
	CData::Serialize(ar);
	if (ar.IsStoring()) {
		ar << m_start_x << m_start_y;
		ar << m_end_x << m_end_y;
		ar << m_nMojiShu;
		ar << m_dSizeX << m_dSizeY;
		ar << m_dKankaku << m_degKakudo;
		ar << m_strFontName;
		ar << m_string;
	}
	else {
		ar >> m_start_x >> m_start_y;
		ar >> m_end_x >> m_end_y;
		ar >> m_nMojiShu;
		ar >> m_dSizeX >> m_dSizeY;
		ar >> m_dKankaku >> m_degKakudo;
		ar >> m_strFontName;
		ar >> m_string;
	}
}
