#include "pch.h"
#include "CDataSunpou.h"

IMPLEMENT_SERIAL(CDataSunpou, CData, JWW_VERSION | VERSIONABLE_SCHEMA);

void CDataSunpou::Serialize(CArchive& ar)
{
	CData::Serialize(ar);
	if (ar.IsStoring()) {
		m_Sen.Serialize(ar);
		m_Moji.Serialize(ar);
		if (CData::s_FileVersion >= 420) { //Ver.4.20à»ç~
			ar << (WORD)m_bSxfMode;
			m_SenHo1.Serialize(ar);
			m_SenHo2.Serialize(ar);
			m_Ten1.Serialize(ar);
			m_Ten2.Serialize(ar);
			m_TenHo1.Serialize(ar);
			m_TenHo2.Serialize(ar);
		}

	}
	else {
		m_Sen.Serialize(ar);
		m_Moji.Serialize(ar);
		if (CData::s_FileVersion >= 420) { //Ver.4.20à»ç~
			ar >> (WORD)m_bSxfMode;
			m_SenHo1.Serialize(ar);
			m_SenHo2.Serialize(ar);
			m_Ten1.Serialize(ar);
			m_Ten2.Serialize(ar);
			m_TenHo1.Serialize(ar);
			m_TenHo2.Serialize(ar);
		}
	}
}
