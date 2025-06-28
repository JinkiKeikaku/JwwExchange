#pragma once
#include "pch.h"
#include "JwwCommon.h"
#include "CJwwWriterBase.h"
#include "CJwwClipHeader.h"
class CJwwClipWriter : public CJwwWriterBase
{
public:
	CJwwClipHeader* m_pHeader = NULL;
public:
	CJwwClipWriter();
	virtual ~CJwwClipWriter();
	virtual void WriteFileType(CArchive& ar);
	virtual void WriteHeader(CArchive& ar);
	void InitHeader(CJwwClipHeader* pHeader);
};

