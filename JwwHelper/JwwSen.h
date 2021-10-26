#pragma once
#include "JwwData.h"
#include "CDataSen.h"
namespace JwwHelper {
	public ref class JwwSen :public JwwData
	{
	public:
		JwwSen() : JwwData(new CDataSen(), false) {}
	internal:
		JwwSen(CDataSen* pData) : JwwData(pData, false) {}

		/// <summary>
		/// 寸法線で使うコンストラクタ。dataは参照を保持して削除されない
		/// </summary>
		JwwSen(CDataSen& data) : JwwData(&data, true) {}
	public:
		virtual String^ ToString() override {
			return String::Format("{0} ({1:F2}, {2:F2})-({3:F2}, {4:F2})", 
				JwwData::ToString(), m_start_x, m_start_y, m_end_x, m_end_y
			);
			//	gcnew  String(
			//	JwwData::ToString() +
			//	" X0:" + m_start_x + " Y0:" + m_start_y + " X1:" + m_end_x + " Y1:" + m_end_y
			//);
		}
	public:
		property double m_start_x {
			double get() { return ((CDataSen*)m_pData)->m_start_x; }
			void set(double value) { ((CDataSen*)m_pData)->m_start_x = value; }
		};
		property double m_start_y {
			double get() { return ((CDataSen*)m_pData)->m_start_y; }
			void set(double value) { ((CDataSen*)m_pData)->m_start_y = value; }
		};
		property double m_end_x {
			double get() { return ((CDataSen*)m_pData)->m_end_x; }
			void set(double value) { ((CDataSen*)m_pData)->m_end_x = value; }
		};
		property double m_end_y {
			double get() { return ((CDataSen*)m_pData)->m_end_y; }
			void set(double value) { ((CDataSen*)m_pData)->m_end_y = value; }
		};
	};

}