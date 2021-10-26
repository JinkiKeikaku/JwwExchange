#pragma once
#include "CData.h"

class CDataSen : public CData
{
	DECLARE_SERIAL(CDataSen)

public:
	CDataSen() {}
	double m_start_x;
	double m_start_y;
	double m_end_x;
	double m_end_y;

	void Serialize(CArchive& ar);
};

