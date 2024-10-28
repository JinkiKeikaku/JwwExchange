#pragma once
#include "CJwwClipHeader.h"
#include "JwwUtility.h"
#include "WrapArray.h"
namespace JwwHelper {

    public ref class JwwClipHeader
    {
    private:
        CJwwClipHeader* m_pHeader;
        WrapArray<double>^ _m_Scales;
        void initArrays() {
            _m_Scales = gcnew WrapArray<double>(m_pHeader->m_Scales, 16);
        }
    internal:
        JwwClipHeader(CJwwClipHeader* pHeader) {
            m_pHeader = pHeader;
            initArrays();
        }
        JwwClipHeader() {
            m_pHeader = new CJwwClipHeader();
            initArrays();
        }
    public:
        ~JwwClipHeader() { this->!JwwClipHeader(); }
        !JwwClipHeader() { delete m_pHeader; }
    public:
        property double m_Origin_x {
            double get() { return m_pHeader->m_Origin_x; }
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
    internal:
        CJwwClipHeader* GetNativeHeader() {
            return m_pHeader;
        }


    };


}