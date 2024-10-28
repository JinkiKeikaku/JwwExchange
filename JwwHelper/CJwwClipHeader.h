#pragma once
#include "pch.h"
#include "JwwCommon.h"
class CJwwClipHeader
{
public:
    double m_Origin_x = 0.0;
    double m_Origin_y = 0.0;
    double m_Scales[16];
public:
    CJwwClipHeader();
    ~CJwwClipHeader();
    void Read(CArchive& ar);
    void Write(CArchive& ar);
    CJwwClipHeader* Clone();


};

