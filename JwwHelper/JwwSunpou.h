#pragma once
#include "JwwData.h"
#include "JwwSen.h"
#include "JwwMoji.h"
#include "JwwTen.h"
#include "CDataSunpou.h"

namespace JwwHelper {
    /// <summary>
    /// ê°ñ@ê}å`ÅB
    /// </summary>
    public ref class JwwSunpou :public JwwData
    {
		JwwSen^ _m_Sen;
		JwwMoji^ _m_Moji;

		JwwSen^ _m_SenHo1;
		JwwSen^ _m_SenHo2;
		JwwTen^ _m_Ten1;
		JwwTen^ _m_Ten2;
		JwwTen^ _m_TenHo1;
		JwwTen^ _m_TenHo2;

		void CopyReference() {
			_m_Sen = gcnew JwwSen(((CDataSunpou*)m_pData)->m_Sen);
			_m_Moji = gcnew JwwMoji(((CDataSunpou*)m_pData)->m_Moji);
			_m_SenHo1 = gcnew JwwSen(((CDataSunpou*)m_pData)->m_SenHo1);
			_m_SenHo1 = gcnew JwwSen(((CDataSunpou*)m_pData)->m_SenHo2);
			_m_Ten1 = gcnew JwwTen(((CDataSunpou*)m_pData)->m_Ten1);
			_m_Ten2 = gcnew JwwTen(((CDataSunpou*)m_pData)->m_Ten2);
			_m_TenHo1 = gcnew JwwTen(((CDataSunpou*)m_pData)->m_TenHo1);
			_m_TenHo2 = gcnew JwwTen(((CDataSunpou*)m_pData)->m_TenHo2);
		}
	public:
		JwwSunpou() : JwwData(new CDataSunpou(), false) {
			CopyReference();
		}
	internal:
		JwwSunpou(CDataSunpou* pData) : JwwData(pData, false) {
			CopyReference();
		}
	public:
		property short m_bSxfMode {
			short get() { return ((CDataSunpou*)m_pData)->m_bSxfMode; }
			void set(short value) { ((CDataSunpou*)m_pData)->m_bSxfMode = value; }
		}
		property JwwSen^ m_Sen {
			JwwSen^ get() { return _m_Sen; }
		};
		property JwwMoji^ m_Moji {
			JwwMoji^ get() { return _m_Moji; }
		};
		property JwwSen^ m_SenHo1 {
			JwwSen^ get() { return _m_SenHo1; }
		};
		property JwwSen^ m_SenHo2 {
			JwwSen^ get() { return _m_SenHo2; }
		};
		property JwwTen^ m_Ten1 {
			JwwTen^ get() { return _m_Ten1; }
		};
		property JwwTen^ m_Ten2 {
			JwwTen^ get() { return _m_Ten2; }
		};
		property JwwTen^ m_TenHo1 {
			JwwTen^ get() { return _m_TenHo1; }
		};
		property JwwTen^ m_TenHo2 {
			JwwTen^ get() { return _m_TenHo2; }
		};
	};
}
