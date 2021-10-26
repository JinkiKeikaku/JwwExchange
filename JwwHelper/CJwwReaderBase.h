#pragma once
#include "CData.h"
#include "CDataList.h"


class CJwwReaderBase : public CObject
{
protected:
	CString m_TmpFolder;
public:
	CTypedPtrList<CObList, CData*> m_DataList;
	CTypedPtrList<CObList, CDataList*>m_DataListList; //ブロックデータ定義部のリスト
public:
	//[temporaryFolder]画像同梱のファイル保存先。NULLの場合は画像同梱のファイルを展開しない。
	//[temporaryFolder]の終わりは'\'であること。また、そのフォルダーは作成済みであること。
	CJwwReaderBase(LPCTSTR temporaryFolder = NULL);
	virtual ~CJwwReaderBase();
	virtual void ReadFileType(CArchive& ar) = 0;
	virtual void ReadHeader(CArchive& ar) = 0;
	void Read(LPCTSTR path);
	void ReadData(CArchive& ar);
	void ReadDataList(CArchive& ar);
	//void ReadImage(CArchive& ar);
	

};

