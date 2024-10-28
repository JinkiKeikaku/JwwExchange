#pragma once
#include "CJwwReaderBase.h"
#include "CJwwClipHeader.h"
#include<vector>

class CJwwClipReader : public CJwwReaderBase
{
public:
	CJwwClipHeader* m_pHeader = NULL;

public:
	CJwwClipReader();
	~CJwwClipReader();

	virtual void ReadFileType(CArchive& ar);
	virtual void ReadHeader(CArchive& ar);
};

