#include "pch.h"
#include "CDataEnko.h"


IMPLEMENT_SERIAL(CDataEnko, CData, JWW_VERSION | VERSIONABLE_SCHEMA);
void CDataEnko::Serialize(CArchive& ar)
{
	CData::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << m_start_x << m_start_y << m_dHankei
			<< m_radKaishiKaku<< m_radEnkoKaku<< m_radKatamukiKaku
			<< m_dHenpeiRitsu
			<< m_bZenEnFlg;
	}
	else
	{
		ar >> m_start_x >> m_start_y >> m_dHankei
			>> m_radKaishiKaku >> m_radEnkoKaku >> m_radKatamukiKaku
			>> m_dHenpeiRitsu
			>> m_bZenEnFlg;
	}
}
