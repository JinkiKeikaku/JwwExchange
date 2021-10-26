#pragma once
#include "CData.h"
#include "CDataList.h"


class CJwwReaderBase : public CObject
{
protected:
	CString m_TmpFolder;
public:
	CTypedPtrList<CObList, CData*> m_DataList;
	CTypedPtrList<CObList, CDataList*>m_DataListList; //�u���b�N�f�[�^��`���̃��X�g
public:
	//[temporaryFolder]�摜�����̃t�@�C���ۑ���BNULL�̏ꍇ�͉摜�����̃t�@�C����W�J���Ȃ��B
	//[temporaryFolder]�̏I����'\'�ł��邱�ƁB�܂��A���̃t�H���_�[�͍쐬�ς݂ł��邱�ƁB
	CJwwReaderBase(LPCTSTR temporaryFolder = NULL);
	virtual ~CJwwReaderBase();
	virtual void ReadFileType(CArchive& ar) = 0;
	virtual void ReadHeader(CArchive& ar) = 0;
	void Read(LPCTSTR path);
	void ReadData(CArchive& ar);
	void ReadDataList(CArchive& ar);
	//void ReadImage(CArchive& ar);
	

};

