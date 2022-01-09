#include "pch.h"
#include "CData.h"
#include "pch.h"
#include "CData.h"
#include "CJwwHeader.h"

IMPLEMENT_SERIAL(CData, CObject, JWW_VERSION | VERSIONABLE_SCHEMA);

int CData::s_FileVersion = JWW_VERSION;


CData::CData() {
	m_lGroup = 0; //曲線属性番号
	m_nPenStyle = 1; //線種番号
	m_nPenColor = 1; //線⾊番号
	m_nPenWidth = 0;//線⾊幅
	m_nLayer = 0; //レイヤ番号
	m_nGLayer = 0; //レイヤグループ番号
	m_sFlg = 0; //属性フラグ
}


void CData::Serialize(CArchive& ar)
{
	if (ar.IsStoring()) {
		ar << m_lGroup; //曲線属性番号
		ar << m_nPenStyle; //線種番号
		ar << m_nPenColor; //線⾊番号
		ar << m_nPenWidth;//線⾊幅
		ar << m_nLayer; //レイヤ番号
		ar << m_nGLayer; //レイヤグループ番号
		ar << m_sFlg; //属性フラグ
	}
	else {
		ar >> m_lGroup; //曲線属性番号
		ar >> m_nPenStyle; //線種番号
		ar >> m_nPenColor; //線⾊番号
		//VersionはSchema使ってないみたいなんですよ。Headerの情報を使ってるみたい。時々両者が等しくない時がある
		if (CData::s_FileVersion >= 351) { //Ver.3.51以降
			ar >> m_nPenWidth;//線⾊幅
		}
		else {
			m_nPenWidth = 0;
		}
		ar >> m_nLayer; //レイヤ番号
		ar >> m_nGLayer; //レイヤグループ番号
		ar >> m_sFlg; //属性フラグ
	}
}

void CData::CopyFrom(CData* src) {
	m_lGroup = src->m_lGroup;
	m_nPenStyle = src->m_nPenStyle;
	m_nPenColor = src->m_nPenColor;
	m_nPenWidth = src->m_nPenWidth;
	m_nLayer = src->m_nLayer;
	m_nGLayer = src->m_nGLayer;
	m_sFlg = src->m_sFlg;
}

CData* CData::Clone(){
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CMemFile mem;
	CArchive store(&mem, CArchive::store);
	store.SetObjectSchema(JWW_VERSION);
	store << this;
	store.Close();
	DWORD len = mem.GetLength();
	BYTE* buf = mem.Detach();
	mem.Close();
	CMemFile tmp(buf, len);
	CArchive load(&tmp, CArchive::load);
	load.SetObjectSchema(JWW_VERSION);
	CData* data = NULL;
	load >> data;
	ASSERT_VALID(data);
	load.Close();
	tmp.Close();
	free(buf);
	return data;

}




