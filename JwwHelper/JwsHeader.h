#pragma once
using namespace System;
#include "CJwsHeader.h"
#include "JwwUtility.h"
#include "WrapArray.h"

namespace JwwHelper {
    public ref class JwsHeader
    {
    private:
        CJwsHeader* m_pHeader;
        WrapArray<double>^ _m_Scales;
        void initArrays() {
            _m_Scales = gcnew WrapArray<double>(m_pHeader->m_Scales, 16);
        }
    internal:
        JwsHeader(CJwsHeader* pHeader) {
            m_pHeader = pHeader;
            initArrays();
        }
        JwsHeader() {
            m_pHeader = new CJwsHeader();
            initArrays();
        }
    public:
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

        property WrapArray<double>^ m_Scales {
            WrapArray<double>^ get() {
                return _m_Scales;
            }
        }

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
        CJwsHeader* GetNativeHeader() {
            return m_pHeader;
        }

    };
}

