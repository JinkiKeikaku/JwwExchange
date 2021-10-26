#pragma once
#include "JwwData.h"
#include "CDataBlock.h"

namespace JwwHelper {
    public ref class JwwBlock :
        public JwwData
    {
    internal:
        JwwBlock(CDataBlock* data) : JwwData(data, false) {}
    public:
        JwwBlock() : JwwData(new CDataBlock(), true) {}
        property double m_DPKijunTen_x {
            double get() { return ((CDataBlock*)m_pData)->m_DPKijunTen_x; }
            void set(double value) { ((CDataBlock*)m_pData)->m_DPKijunTen_x = value; }
        };
        property double m_DPKijunTen_y {
            double get() { return ((CDataBlock*)m_pData)->m_DPKijunTen_y; }
            void set(double value) { ((CDataBlock*)m_pData)->m_DPKijunTen_y = value; }
        };
        property double m_dBairitsuX {
            double get() { return ((CDataBlock*)m_pData)->m_dBairitsuX; }
            void set(double value) { ((CDataBlock*)m_pData)->m_dBairitsuX = value; }
        };
        property double m_dBairitsuY {
            double get() { return ((CDataBlock*)m_pData)->m_dBairitsuY; }
            void set(double value) { ((CDataBlock*)m_pData)->m_dBairitsuY = value; }
        };
        property double m_radKaitenKaku {
            double get() { return ((CDataBlock*)m_pData)->m_radKaitenKaku; }
            void set(double value) { ((CDataBlock*)m_pData)->m_radKaitenKaku = value; }
        };
        property int m_nNumber {
            int get() { return ((CDataBlock*)m_pData)->m_nNumber; }
            void set(int value) { ((CDataBlock*)m_pData)->m_nNumber = value; }
        };

    };
}

