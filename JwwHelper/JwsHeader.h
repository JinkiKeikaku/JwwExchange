#pragma once
using namespace System;
#include "CJwsHeader.h"

namespace JwwHelper {
    public ref class JwsHeader
    {
    public:
        JwsHeader() { m_pHeader = new CJwsHeader(); }
        JwsHeader(CJwsHeader* pHeader) { m_pHeader = pHeader; }
        ~JwsHeader() { this->!JwsHeader(); }
        !JwsHeader() { delete m_pHeader; }
    public:
        property double m_Origin_x {
            double get(){ return m_pHeader->m_Origin_x; }
            void set(double value) { m_pHeader->m_Origin_x = value; }
        };
        property double m_Origin_y {
            double get() { return m_pHeader->m_Origin_y; }
            void set(double value) { m_pHeader->m_Origin_y = value; }
        };
        property double m_Scales[int]{
            double get(int index) { return m_pHeader->m_Scales[index]; }
            void set(int index, double value) { m_pHeader->m_Scales[index] = value; }
        };
        property double m_Bounds_Left {
            double get() { return m_pHeader->m_Bounds_Left; }
            void set(double value) { m_pHeader->m_Bounds_Left = value; }
        };
        property double m_Bounds_Bottom {
            double get() { return m_pHeader->m_Bounds_Bottom; }
            void set(double value) { m_pHeader->m_Bounds_Bottom = value; }
        };
        property double m_Bounds_Right {
            double get() { return m_pHeader->m_Bounds_Right; }
            void set(double value) { m_pHeader->m_Bounds_Right = value; }
        };
        property double m_Bounds_Top {
            double get() { return m_pHeader->m_Bounds_Top; }
            void set(double value) { m_pHeader->m_Bounds_Top = value; }
        };
    internal:
        CJwsHeader* m_pHeader;
    };
}

