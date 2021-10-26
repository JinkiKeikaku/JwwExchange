#pragma once
#include "CData.h"
class CDataList :public CData
{
	DECLARE_SERIAL(CDataList)

public:
	INT m_nNumber; //通しNo
	BOOL m_bReffered; //実際に参照されているか
	CTime m_time; //作成された時刻を⼊れる
	CString m_strName; //ブロックデータの名前
	CTypedPtrList<CObList, CData*>m_DataList;
public:
	CDataList();
	~CDataList();
	void Serialize(CArchive& ar);


};

