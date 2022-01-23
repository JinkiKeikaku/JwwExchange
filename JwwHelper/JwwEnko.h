#pragma once
#include "JwwData.h"
#include"CDataEnko.h"

namespace JwwHelper {
	/// <summary>
	/// ë»â~ÅAë»â~å ÉNÉâÉX
	/// </summary>
	public ref class JwwEnko : public JwwData
	{
	public:
		JwwEnko() : JwwData(new CDataEnko(), false) {}
	internal:
		JwwEnko(CDataEnko* data) : JwwData(data, false) {}
	public:
		virtual String^ ToString() override {
			return String::Format("{0} ({1:F2}, {2:F2}) R:{3:F2} F:{4:F2} A:{5:F2} SA:{6:F2} SW:{7:F2} CF:{8}",
				JwwData::ToString(), m_start_x, m_start_y, 
				m_dHankei, m_dHenpeiRitsu, m_radKatamukiKaku, m_radKaishiKaku, m_radEnkoKaku, m_bZenEnFlg
			);
				//gcnew  String(JwwData::ToString() +
				//" X0:" + m_start_x + " Y0:" + m_start_y + " R:" + m_dHankei + " SA:" + m_radKaishiKaku +
				//" SW:" + m_radEnkoKaku + " A:" + m_radKatamukiKaku + " F:" + m_dHenpeiRitsu +
				//" CF:" + m_bZenEnFlg);
		}
	public:
		property double m_start_x {
			double get() { return ((CDataEnko*)m_pData)->m_start_x; }
			void set(double value) { ((CDataEnko*)m_pData)->m_start_x = value; }
		};
		property double m_start_y {
			double get() { return ((CDataEnko*)m_pData)->m_start_y; }
			void set(double value) { ((CDataEnko*)m_pData)->m_start_y = value; }
		};
		property double m_dHankei {
			double get() { return ((CDataEnko*)m_pData)->m_dHankei; }
			void set(double value) { ((CDataEnko*)m_pData)->m_dHankei = value; }
		};
		property double m_radKaishiKaku {
			double get() { return ((CDataEnko*)m_pData)->m_radKaishiKaku; }
			void set(double value) { ((CDataEnko*)m_pData)->m_radKaishiKaku = value; }
		};
		property double m_radEnkoKaku {
			double get() { return ((CDataEnko*)m_pData)->m_radEnkoKaku; }
			void set(double value) { ((CDataEnko*)m_pData)->m_radEnkoKaku = value; }
		};
		property double m_radKatamukiKaku {
			double get() { return ((CDataEnko*)m_pData)->m_radKatamukiKaku; }
			void set(double value) { ((CDataEnko*)m_pData)->m_radKatamukiKaku = value; }
		};
		property double m_dHenpeiRitsu {
			double get() { return ((CDataEnko*)m_pData)->m_dHenpeiRitsu; }
			void set(double value) { ((CDataEnko*)m_pData)->m_dHenpeiRitsu = value; }
		};

		/// <summary>
		/// ÇΩÇ‘ÇÒ1Ç»ÇÁâ~å Ç≈Ç»Ç≠â~Ç…Ç»ÇÈÅB
		/// </summary>
		property int m_bZenEnFlg {
			int get() { return ((CDataEnko*)m_pData)->m_bZenEnFlg; }
			void set(int value) { ((CDataEnko*)m_pData)->m_bZenEnFlg = value; }
		};


	};

}