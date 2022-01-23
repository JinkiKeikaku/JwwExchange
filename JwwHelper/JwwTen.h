#pragma once
#include "JwwData.h"
#include "CDataTen.h"

namespace JwwHelper {
    /// <summary>
    /// ì_ê}å`ÅB
    /// </summary>
    public ref class JwwTen :
        public JwwData
    {
    public:
        JwwTen() : JwwData(new CDataTen(), true) {}
    internal:
        JwwTen(CDataTen* data) : JwwData(data, false) {}
        JwwTen(CDataTen& data) : JwwData(&data, true) {}

    public:
        property double m_start_x {
            double get() { return ((CDataTen*)m_pData)->m_start_x; }
            void set(double value) { ((CDataTen*)m_pData)->m_start_x = value; }
        };
        property double m_start_y {
            double get() { return ((CDataTen*)m_pData)->m_start_y; }
            void set(double value) { ((CDataTen*)m_pData)->m_start_y = value; }
        };
        property int m_bKariten {
            int get() { return ((CDataTen*)m_pData)->m_bKariten; }
            void set(int value) { ((CDataTen*)m_pData)->m_bKariten = value; }
        };
        property int m_nCode {
            int get() { return ((CDataTen*)m_pData)->m_nCode; }
            void set(int value) { ((CDataTen*)m_pData)->m_nCode = value; }
        };
        property double m_radKaitenKaku {
            double get() { return ((CDataTen*)m_pData)->m_radKaitenKaku; }
            void set(double value) { ((CDataTen*)m_pData)->m_radKaitenKaku = value; }
        };
        property double m_dBairitsu {
            double get() { return ((CDataTen*)m_pData)->m_dBairitsu; }
            void set(double value) { ((CDataTen*)m_pData)->m_dBairitsu = value; }
        };
    };
}

