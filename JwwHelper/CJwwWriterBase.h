#pragma once
#include "CData.h"
#include "CDataList.h"


class CJwwWriterBase
{
public:
	CTypedPtrList<CObList, CData*> m_DataList;
	CTypedPtrList<CObList, CDataList*>m_DataListList; //ブロックデータ定義部のリスト
public:
	CJwwWriterBase();
	virtual ~CJwwWriterBase();
	virtual void WriteFileType(CArchive& ar) = 0;
	virtual void WriteHeader(CArchive& ar) = 0;
	virtual void Write(LPCTSTR path);
	virtual void WriteImages(CArchive& ar) {}
	void WriteData(CArchive& ar);
	void WriteDataList(CArchive& ar);
};

