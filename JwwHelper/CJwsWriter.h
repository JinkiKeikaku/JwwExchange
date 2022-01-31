#pragma once
#include "CJwwWriterBase.h"
#include "CJwsHeader.h"
#include "CData.h"
#include "CDataList.h"

class CJwsWriter : public CJwwWriterBase
{
public:
	CJwsHeader* m_pHeader = NULL;
public:
	CJwsWriter();
	virtual ~CJwsWriter();
	virtual void WriteFileType(CArchive& ar);
	virtual void WriteHeader(CArchive& ar);
	void InitHeader(CJwsHeader* pHeader);
};

