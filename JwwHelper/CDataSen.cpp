#include "pch.h"
#include "CDataSen.h"
#include "JwwCommon.h"

IMPLEMENT_SERIAL(CDataSen, CData, JWW_VERSION | VERSIONABLE_SCHEMA);

void CDataSen::Serialize(CArchive& ar) {
	CData::Serialize(ar);
	if (ar.IsStoring()) {
		ar << m_start_x << m_start_y;
		ar << m_end_x << m_end_y;
	}
	else {
		ar >> m_start_x >> m_start_y;
		ar >> m_end_x >> m_end_y;
	}
}
//CData* CDataSen::Clone() {
//	CDataSen* s = new CDataSen();
//	s->CopyFrom(this);
//	s->m_start_x = m_start_x;
//	s->m_start_y = m_start_y;
//	s->m_end_x = m_end_x;
//	s->m_end_y = m_end_y;
//	return s;
//}
