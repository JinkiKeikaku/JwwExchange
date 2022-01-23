#pragma once
#include "JwwData.h"
#include "CDataSolid.h"

namespace JwwHelper {
	/// <summary>
	/// ソリッド図形。円弧ソリッドは頑張ってください。
	/// </summary>
	public ref class JwwSolid :
        public JwwData
    {
	public:
        JwwSolid() : JwwData(new CDataSolid(), true) {}
	internal:
		JwwSolid(CDataSolid* data) : JwwData(data, false) {}
	public:
		property double m_start_x {
			double get() { return ((CDataSolid*)m_pData)->m_start_x; }
			void set(double value) { ((CDataSolid*)m_pData)->m_start_x = value; }
		};
		property double m_start_y {
			double get() { return ((CDataSolid*)m_pData)->m_start_y; }
			void set(double value) { ((CDataSolid*)m_pData)->m_start_y = value; }
		};
		property double m_end_x {
			double get() { return ((CDataSolid*)m_pData)->m_end_x; }
			void set(double value) { ((CDataSolid*)m_pData)->m_end_x = value; }
		};
		property double m_end_y {
			double get() { return ((CDataSolid*)m_pData)->m_end_y; }
			void set(double value) { ((CDataSolid*)m_pData)->m_end_y = value; }
		};
		property double m_DPoint2_x {
			double get() { return ((CDataSolid*)m_pData)->m_DPoint2_x; }
			void set(double value) { ((CDataSolid*)m_pData)->m_DPoint2_x = value; }
		};
		property double m_DPoint2_y {
			double get() { return ((CDataSolid*)m_pData)->m_DPoint2_y; }
			void set(double value) { ((CDataSolid*)m_pData)->m_DPoint2_y = value; }
		};
		property double m_DPoint3_x {
			double get() { return ((CDataSolid*)m_pData)->m_DPoint3_x; }
			void set(double value) { ((CDataSolid*)m_pData)->m_DPoint3_x = value; }
		};
		property double m_DPoint3_y {
			double get() { return ((CDataSolid*)m_pData)->m_DPoint3_y; }
			void set(double value) { ((CDataSolid*)m_pData)->m_DPoint3_y = value; }
		};
		property int m_Color {
			int get() { return ((CDataSolid*)m_pData)->m_Color; }
			void set(int value) { ((CDataSolid*)m_pData)->m_Color = value; }
		};

    };

}