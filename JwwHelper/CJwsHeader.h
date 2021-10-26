#pragma once
#include "JwwCommon.h"
class CJwsHeader
{
public:
    DWORD  m_jwsDataVersion = 700;
    DWORD m_Tmp1[6];
    double m_Tmp2[6];
    double m_Origin_x = 0.0;
    double m_Origin_y = 0.0;
    double m_Scales[16]; 
    double m_Bounds_Left = 0.0;
    double m_Bounds_Bottom = 0.0;
    double m_Bounds_Right = 0.0;
    double m_Bounds_Top = 0.0;
public :
    CJwsHeader();
    ~CJwsHeader();
    void Read(CArchive& ar);
    void Write(CArchive& ar);
    CJwsHeader* Clone();

};

