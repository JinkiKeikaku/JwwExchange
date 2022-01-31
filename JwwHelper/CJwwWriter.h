#pragma once
#include "CJwwWriterBase.h"
#include "CJwwHeader.h"
#include "CData.h"
#include "CDataList.h"
#include "CJwwImage.h"
#include<vector>


class CJwwWriter : public CJwwWriterBase
{
public:
	CJwwHeader* m_pHeader = NULL;
	//CTypedPtrList<CObList, CData*> m_DataList;
	//CTypedPtrList<CObList, CDataList*>m_DataListList; //ブロックデータ定義部のリスト
	std::vector<CJwwImage*> m_Images;
public:
	CJwwWriter();
	virtual ~CJwwWriter();
	void InitHeader(LPCTSTR path);
	void InitHeader(CJwwHeader* pHeader);
private:
	virtual void WriteFileType(CArchive& ar);
	virtual void WriteHeader(CArchive& ar);
	virtual void WriteImages(CArchive& ar);

};

