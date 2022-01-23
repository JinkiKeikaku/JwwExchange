#pragma once
using namespace System;
#include "JwwData.h"
#include "CDataMoji.h"
namespace JwwHelper {
	public ref class JwwMoji :public JwwData
	{
	public:
		JwwMoji() : JwwData(new CDataMoji(), false) {}
	internal:
		JwwMoji(CDataMoji* pData) : JwwData(pData, false) {}
		JwwMoji(CDataMoji& data) : JwwData(&data, true) {}
	public:
		virtual String^ ToString() override {
			return String::Format("{0} ({1:F2}, {2:F2})-({3:F2}, {4:F2}) SX:{5:F1} SY:{6:F1} Font:{7} Text:{8}",
				JwwData::ToString(), m_start_x, m_start_y, m_end_x, m_end_y,
				m_dSizeX, m_dSizeY, m_strFontName, m_string
			);
			//return gcnew  String(JwwData::ToString() +
			//	" X0:" + m_start_x + " Y0:" + m_start_y + " X1:" + m_end_x + " Y1:" + m_end_y +
			//	" m_nMojiShu:" + m_nMojiShu + " SX:" + m_dSizeX + " SY:" + m_dSizeY +
			//	" K:" + m_dKankaku + " A:" + m_degKakudo + " F:" + m_strFontName + " S:" + m_string);
		}
	public:
		/// <summary>
		/// 始点X座標。始点は左下。
		/// </summary>
		property double m_start_x {
			double get() { return ((CDataMoji*)m_pData)->m_start_x; }
			void set(double value) { ((CDataMoji*)m_pData)->m_start_x = value; }
		};
		/// <summary>
		/// 始点y座標。始点は左下。
		/// </summary>
		property double m_start_y {
			double get() { return ((CDataMoji*)m_pData)->m_start_y; }
			void set(double value) { ((CDataMoji*)m_pData)->m_start_y = value; }
		};
		/// <summary>
		/// 終点X座標。始点は右下。
		/// </summary>
		property double m_end_x {
			double get() { return ((CDataMoji*)m_pData)->m_end_x; }
			void set(double value) { ((CDataMoji*)m_pData)->m_end_x = value; }
		};
		/// <summary>
		/// 終点y座標。始点は右下。
		/// </summary>
		property double m_end_y {
			double get() { return ((CDataMoji*)m_pData)->m_end_y; }
			void set(double value) { ((CDataMoji*)m_pData)->m_end_y = value; }
		};
		property int m_nMojiShu {
			int get() { return ((CDataMoji*)m_pData)->m_nMojiShu; }
			void set(int value) { ((CDataMoji*)m_pData)->m_nMojiShu = value; }
		};
		property double m_dSizeX {
			double get() { return ((CDataMoji*)m_pData)->m_dSizeX; }
			void set(double value) { ((CDataMoji*)m_pData)->m_dSizeX = value; }
		};
		property double m_dSizeY {
			double get() { return ((CDataMoji*)m_pData)->m_dSizeY; }
			void set(double value) { ((CDataMoji*)m_pData)->m_dSizeY = value; }
		};
		property double m_dKankaku {
			double get() { return ((CDataMoji*)m_pData)->m_dKankaku; }
			void set(double value) { ((CDataMoji*)m_pData)->m_dKankaku = value; }
		};
		property double m_degKakudo {
			double get() { return ((CDataMoji*)m_pData)->m_degKakudo; }
			void set(double value) { ((CDataMoji*)m_pData)->m_degKakudo = value; }
		};
		property String^ m_strFontName {
			String^ get() {
				return gcnew String(CA2W(((CDataMoji*)m_pData)->m_strFontName.GetString()));
			}
			void set(String^ value) {
				pin_ptr<const WCHAR> str = PtrToStringChars(value);
				CW2A astr(str);
				((CDataMoji*)m_pData)->m_strFontName = astr;
			}
		};
		property String^ m_string {
			String^ get() {
				return gcnew String(CA2W(((CDataMoji*)m_pData)->m_string.GetString()));
			}
			void set(String^ value) {
				pin_ptr<const WCHAR> str = PtrToStringChars(value);
				CW2A astr(str);
				((CDataMoji*)m_pData)->m_string = astr;
			}
		};
	};
}


