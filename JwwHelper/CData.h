#pragma once
#include "pch.h"
#include "CJwwHeader.h"


class CData : public CObject
{
	DECLARE_SERIAL(CData)
public:
	static int s_FileVersion;
public:
	DWORD m_lGroup = 0; //曲線属性番号
	BYTE m_nPenStyle = 1; //線種番号
	WORD m_nPenColor = 1; //線⾊番号
	WORD m_nPenWidth = 0;//線⾊幅
	WORD m_nLayer = 0; //レイヤ番号
	WORD m_nGLayer = 0; //レイヤグループ番号
	WORD m_sFlg = 0; //属性フラグ
public:
	CData();
	void CopyFrom(CData* src);
	void Serialize(CArchive& ar);
	virtual CData* Clone();

};

