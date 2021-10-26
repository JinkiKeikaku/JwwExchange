#pragma once
#include "CData.h"
class CDataEnko :public CData
{
	DECLARE_SERIAL(CDataEnko)
public:
	double m_start_x;
	double m_start_y;
	double m_dHankei;
	double m_radKaishiKaku;
	double m_radEnkoKaku;
	double m_radKatamukiKaku;
	double m_dHenpeiRitsu;
	DWORD m_bZenEnFlg;
public:
	virtual void Serialize(CArchive& ar);
};

