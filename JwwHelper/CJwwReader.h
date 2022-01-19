#pragma once

#include "CJwwReaderBase.h"
#include "CJwwHeader.h"
#include "CJwwImage.h"
#include<vector>

class CJwwReader :public CJwwReaderBase
{
public:
	CJwwHeader* m_pHeader = NULL;
	std::vector<CJwwImage*> m_Images;

public:
	CJwwReader();
	virtual ~CJwwReader();
private:
	virtual void ReadFileType(CArchive& ar);
	virtual void ReadHeader(CArchive& ar);
	virtual void ReadImages(CArchive& ar);

};

