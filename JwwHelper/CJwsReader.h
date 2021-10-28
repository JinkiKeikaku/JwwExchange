#pragma once
#include "CJwwReaderBase.h"
#include "CJwsHeader.h"

class CJwsReader : public CJwwReaderBase
{
public:
	CJwsHeader* m_pHeader = NULL;
public:
	CJwsReader();
	~CJwsReader();
private:
	virtual void ReadFileType(CArchive& ar);
	virtual void ReadHeader(CArchive& ar);


};


