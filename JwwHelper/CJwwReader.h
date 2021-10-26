#pragma once
#include "CJwwReaderBase.h"
#include "CJwwHeader.h"
class CJwwReader :public CJwwReaderBase
{
public:
	CJwwHeader* m_pHeader = NULL;
public:
	//[temporaryFolder]画像同梱のファイル保存先。NULLの場合は画像同梱のファイルを展開しない。
	//[temporaryFolder]の終わりは'\'であること。また、そのフォルダーは作成済みであること。
	CJwwReader(LPCTSTR temporaryFolder = NULL);
	virtual ~CJwwReader();
private:
	virtual void ReadFileType(CArchive& ar);
	virtual void ReadHeader(CArchive& ar);

};

