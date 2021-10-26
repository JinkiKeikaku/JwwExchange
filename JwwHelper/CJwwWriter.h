#pragma once
#include "CJwwHeader.h"
#include "CData.h"
#include "CDataList.h"

class CImageData {
public:
	CString m_ImagePath;	//���ۂɕۑ�����Ă���摜�̃p�X
	CString m_JwwPath;		//Jww�ɋL�^�����p�X�B�ǂ�Ȍ`�����͎��ۂɓǂ�Ŋm�F���Ă��������I
public:
	CImageData(LPCTSTR imagePath = NULL, LPCTSTR jwwPath = NULL) {
		m_ImagePath = imagePath;
		m_JwwPath = jwwPath;
	}
};

class CJwwWriter
{
public:
	CJwwHeader* m_pHeader = NULL;
	CTypedPtrList<CObList, CData*> m_DataList;
	CTypedPtrList<CObList, CDataList*>m_DataListList; //�u���b�N�f�[�^��`���̃��X�g
	CList<CImageData, const CImageData&> m_ImageDatas;
public:
	CJwwWriter();
	virtual ~CJwwWriter();
	void Write(LPCTSTR path);
	void InitHeader(LPCTSTR path);
	void InitHeader(CJwwHeader* pHeader);
private:
	void WriteHeader(CArchive& ar);
	void WriteData(CArchive& ar);
	void WriteDataList(CArchive& ar);
	void WriteImage(CArchive& ar);

};

