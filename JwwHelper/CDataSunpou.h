#pragma once
#include "CData.h"
#include "CDataSen.h"
#include "CDataMoji.h"
#include "CDataTen.h"
class CDataSunpou :public CData{
	DECLARE_SERIAL(CDataSunpou)
public:
	CDataSen m_Sen;
	CDataMoji m_Moji;
	WORD m_bSxfMode;
	CDataSen m_SenHo1;
	CDataSen m_SenHo2;
	CDataTen m_Ten1;
	CDataTen m_Ten2;
	CDataTen m_TenHo1;
	CDataTen m_TenHo2;
public:
	virtual void Serialize(CArchive& ar);

};

