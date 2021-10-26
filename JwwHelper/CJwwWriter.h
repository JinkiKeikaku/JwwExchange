#pragma once
#include "CJwwHeader.h"
#include "CData.h"
#include "CDataList.h"

class CImageData {
public:
	CString m_ImagePath;	//実際に保存されている画像のパス
	CString m_JwwPath;		//Jwwに記録されるパス。どんな形式かは実際に読んで確認してください！
public:
	CImageData(LPCTSTR imagePath = NULL, LPCTSTR jwwPath = NULL) {
		m_ImagePath = imagePath;
		m_JwwPath = jwwPath;
	}
};

class CJwwWriter
{
public:
	CJwwHeader* m_pHeader = NULL;
	CTypedPtrList<CObList, CData*> m_DataList;
	CTypedPtrList<CObList, CDataList*>m_DataListList; //ブロックデータ定義部のリスト
	CList<CImageData, const CImageData&> m_ImageDatas;
public:
	CJwwWriter();
	virtual ~CJwwWriter();
	void Write(LPCTSTR path);
	void InitHeader(LPCTSTR path);
	void InitHeader(CJwwHeader* pHeader);
private:
	void WriteHeader(CArchive& ar);
	void WriteData(CArchive& ar);
	void WriteDataList(CArchive& ar);
	void WriteImage(CArchive& ar);

};

