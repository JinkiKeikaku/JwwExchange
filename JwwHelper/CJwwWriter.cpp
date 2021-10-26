#include "pch.h"
#include "CJwwWriter.h"
#include "CJwwReader.h"

CJwwWriter::CJwwWriter() {
	m_pHeader = new CJwwHeader();
}

CJwwWriter::~CJwwWriter() {
	delete m_pHeader;
	{
		POSITION pos = m_DataList.GetHeadPosition();
		while (pos != NULL) {
			CData* data = m_DataList.GetNext(pos);
			delete data;
		}
	}
	{
		POSITION pos = m_DataListList.GetHeadPosition();
		while (pos != NULL) {
			CDataList* data = m_DataListList.GetNext(pos);
			delete data;
		}
	}
}

void CJwwWriter::Write(LPCTSTR path) {
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CFile file;
	file.Open(path, CFile::modeWrite | CFile::modeCreate);
	CArchive ar(&file, CArchive::store);
	BYTE buf[8];
	memcpy(buf, "JwwData.", 8);
	ar.Write(buf, 8);
	WriteHeader(ar);
	WriteData(ar);
	WriteDataList(ar);
	WriteImage(ar);
	ar.Close();
}

void CJwwWriter::InitHeader(LPCTSTR path) {
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CFile file;
	file.Open(path, CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	BYTE buf[8];
	ar.Read(buf, 8);
	if (memcmp(buf, "JwwData.", 8) != 0)	AfxThrowFileException(CFileException::invalidFile);
	m_pHeader->Read(ar);
	ar.Close();
}

void CJwwWriter::InitHeader(CJwwHeader* pHeader) {
	delete m_pHeader;
	m_pHeader = pHeader->Clone();
}


void CJwwWriter::WriteHeader(CArchive& ar) {
	m_pHeader->Write(ar);
}

void CJwwWriter::WriteData(CArchive& ar) {
	m_DataList.Serialize(ar);
}
void CJwwWriter::WriteDataList(CArchive& ar) {
	m_DataListList.Serialize(ar);
}

void CJwwWriter::WriteImage(CArchive& ar) {
	ar << m_ImageDatas.GetCount();
	POSITION pos = m_ImageDatas.GetHeadPosition();
	while (pos != NULL) {
		const CImageData& p = m_ImageDatas.GetNext(pos);
		ar << p.m_JwwPath;
		CFile f;
		f.Open(p.m_ImagePath, CFile::modeRead);
		DWORD n = f.GetLength();
		BYTE* buf = new BYTE[n];
		f.Read(buf, n);
		ar.Write(buf, n);
	}
}

