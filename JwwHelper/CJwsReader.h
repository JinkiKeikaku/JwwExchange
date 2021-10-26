#pragma once
#include "CJwwReaderBase.h"
#include "CJwsHeader.h"

class CJwsReader : public CJwwReaderBase
{
public:
	CJwsHeader* m_pHeader = NULL;
public:
	//[temporaryFolder]画像同梱のファイル保存先。NULLの場合は画像同梱のファイルを展開しない。
	//[temporaryFolder]の終わりは'\'であること。また、そのフォルダーは作成済みであること。
	CJwsReader(LPCTSTR temporaryFolder = NULL);
	~CJwsReader();
private:
	virtual void ReadFileType(CArchive& ar);
	virtual void ReadHeader(CArchive& ar);


};


