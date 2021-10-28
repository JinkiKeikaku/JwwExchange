#pragma once
class CJwwImage {
public:
	CString m_ImageName;
	int m_Size;
	BYTE* m_pBuffer;
public:
	CJwwImage(CString imageName, BYTE* pBuffer, int size) {
		m_ImageName = imageName;
		m_pBuffer = pBuffer;
		m_Size = size;
	}
	virtual ~CJwwImage() {
		delete[] m_pBuffer;
	}
	CJwwImage* Clone();

};

