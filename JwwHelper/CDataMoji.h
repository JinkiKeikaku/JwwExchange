#pragma once
#include "CData.h"
class CDataMoji : public CData
{
	DECLARE_SERIAL(CDataMoji)

public:
	double m_start_x;
	double m_start_y;
	double m_end_x;
	double m_end_y;
	DWORD m_nMojiShu;
	double m_dSizeX;
	double m_dSizeY;
	double m_dKankaku;
	double m_degKakudo;
	CString m_strFontName;
	CString m_string;

public:
	CDataMoji();
	void Serialize(CArchive& ar);
};


