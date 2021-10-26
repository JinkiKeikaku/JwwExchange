#pragma once
#include "CJwwReaderBase.h"
#include "CJwwHeader.h"
class CJwwReader :public CJwwReaderBase
{
public:
	CJwwHeader* m_pHeader = NULL;
public:
	//[temporaryFolder]�摜�����̃t�@�C���ۑ���BNULL�̏ꍇ�͉摜�����̃t�@�C����W�J���Ȃ��B
	//[temporaryFolder]�̏I����'\'�ł��邱�ƁB�܂��A���̃t�H���_�[�͍쐬�ς݂ł��邱�ƁB
	CJwwReader(LPCTSTR temporaryFolder = NULL);
	virtual ~CJwwReader();
private:
	virtual void ReadFileType(CArchive& ar);
	virtual void ReadHeader(CArchive& ar);

};

