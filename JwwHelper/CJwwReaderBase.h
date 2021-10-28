#pragma once
#include "CData.h"
#include "CDataList.h"


class CJwwReaderBase : public CObject
{

public:
	CTypedPtrList<CObList, CData*> m_DataList;
	CTypedPtrList<CObList, CDataList*>m_DataListList; //�u���b�N�f�[�^��`���̃��X�g
public:
	CJwwReaderBase();
	virtual ~CJwwReaderBase();
	virtual void ReadFileType(CArchive& ar) = 0;
	virtual void ReadHeader(CArchive& ar) = 0;
	virtual void Read(LPCTSTR path);
	void ReadData(CArchive& ar);
	void ReadDataList(CArchive& ar);
	virtual void ReadImages(CArchive& ar) {}


};

