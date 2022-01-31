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
	//Jws�ɂ͓����摜�͖����悤���B
//	virtual void ReadImages(CArchive& ar);


};


