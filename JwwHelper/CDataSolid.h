#pragma once
#include "CData.h"
class CDataSolid :public CData{
	DECLARE_SERIAL(CDataSolid)
public:
	double m_start_x;
	double m_start_y;
	double m_end_x;
	double m_end_y;
	double m_DPoint2_x;
	double m_DPoint2_y;
	double m_DPoint3_x;
	double m_DPoint3_y;
	DWORD m_Color;//RGB
public:
	virtual void Serialize(CArchive& ar);
};

