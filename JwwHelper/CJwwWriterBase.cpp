#include "CJwwWriterBase.h"

CJwwWriterBase::CJwwWriterBase() {
}

CJwwWriterBase::~CJwwWriterBase() {
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

void CJwwWriterBase::Write(CArchive& ar) {
	WriteFileType(ar);
	WriteHeader(ar);
	WriteData(ar);
	WriteDataList(ar);
	WriteImages(ar);
}


void CJwwWriterBase::Write(LPCTSTR path) {
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CFile file;
	file.Open(path, CFile::modeWrite | CFile::modeCreate);
	CArchive ar(&file, CArchive::store);
	try {
		Write(ar);
	}
	finally {
		ar.Close();
	}
}

HANDLE CJwwWriterBase::WriteToMemory() {
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CMemFile mem;
	CArchive ar(&mem, CArchive::store);
	Write(ar);
	ar.Close();
	DWORD len = mem.GetLength();
	HANDLE h = GlobalAlloc(GMEM_MOVEABLE, len);
	if (h == NULL) return NULL;
	byte* pmem = (byte*)GlobalLock(h);
	if (pmem == NULL) {
		GlobalFree(h);
		h = NULL;
	}
	else {
		BYTE* buf = mem.Detach();
		mem.Close();
		memcpy(pmem, buf, len);
		free(buf);
		GlobalUnlock(h);
	}
	return h;
}


void CJwwWriterBase::WriteData(CArchive& ar) {
	m_DataList.Serialize(ar);
}
void CJwwWriterBase::WriteDataList(CArchive& ar) {
	m_DataListList.Serialize(ar);
}

