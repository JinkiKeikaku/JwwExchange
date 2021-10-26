#pragma once
#include "CData.h"
class CDataTen : public CData
{
	DECLARE_SERIAL(CDataTen)
public:
	double m_start_x;
	double m_start_y;
	DWORD m_bKariten;
	DWORD m_nCode;
	double m_radKaitenKaku;
	double m_dBairitsu;
public:
	virtual void Serialize(CArchive& ar);
};

