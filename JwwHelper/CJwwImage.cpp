#include "pch.h"
#include "CJwwImage.h"

CJwwImage* CJwwImage::Clone() {
	BYTE* buffer = new BYTE [m_Size];
	memcpy(buffer, m_pBuffer, m_Size);
	CJwwImage* d = new CJwwImage(m_ImageName, buffer, m_Size);
	return d;
}

