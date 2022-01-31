#pragma once
#include "CJwwReaderBase.h"
#include "CJwsHeader.h"
#include "CJwwImage.h"
#include<vector>

class CJwsReader : public CJwwReaderBase
{
public:
	CJwsHeader* m_pHeader = NULL;
	std::vector<CJwwImage*> m_Images;
public:
	CJwsReader();
	~CJwsReader();
private:
	virtual void ReadFileType(CArchive& ar);
	virtual void ReadHeader(CArchive& ar);
	//Jws‚É‚Í“¯«‰æ‘œ‚Í–³‚¢‚æ‚¤‚¾B
//	virtual void ReadImages(CArchive& ar);


};


