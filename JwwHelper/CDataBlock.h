#pragma once
#include "CData.h"

class CDataBlock :public CData
{
	DECLARE_SERIAL(CDataBlock)

public:
	double m_DPKijunTen_x;
	double m_DPKijunTen_y;
	double m_dBairitsuX;
	double m_dBairitsuY;
	double m_radKaitenKaku;
	DWORD m_nNumber;//ƒ|ƒCƒ“ƒ^‚Å‚È‚­’Ê‚µ”Ô†‚ğ•Û‘¶‚·‚é

public:
	void Serialize(CArchive& ar);
};

