#pragma once
#include "CData.h"
using namespace System;
namespace JwwHelper {
	public ref class JwwData
	{
		bool isReference = false;

	protected:
		JwwData(CData* data, bool isReference) {
			m_pData = data;
			this->isReference = isReference;
		}

	public:
		virtual ~JwwData() {  this->!JwwData();  }
		!JwwData() {
			if(!isReference)	delete this->m_pData;
		}
		CData* Clone() {
			return m_pData->Clone();
		}
	public:
		virtual String^ ToString() override {
			return gcnew  String(
				" G:" + m_lGroup + " PS:" + m_nPenStyle + " PC:" + m_nPenColor + " PW:" + m_nPenWidth +
				" L:" + m_nLayer + " GL:" + m_nGLayer + " F:" + m_sFlg);
		}
	public:
		//曲線属性番号
		property int m_lGroup {
			int get() { return m_pData->m_lGroup; }
			void set(int value) { m_pData->m_lGroup = value; }
		};

		//線種番号
		property byte m_nPenStyle {
			byte get() { return m_pData->m_nPenStyle; }
			void set(byte value) { m_pData->m_nPenStyle = value; }
		};

		//線⾊番号
		property short m_nPenColor {
			short get() { return m_pData->m_nPenColor; }
			void set(short value) { m_pData->m_nPenColor = value; }
		};

		//線⾊幅
		property short m_nPenWidth {
			short get() { return m_pData->m_nPenWidth; }
			void set(short value) { m_pData->m_nPenWidth = value; }
		};

		//レイヤ番号
		property short m_nLayer {
			short get() { return m_pData->m_nLayer; }
			void set(short value) { m_pData->m_nLayer = value; }
		};

		//レイヤグループ番号
		property short m_nGLayer {
			short get() { return m_pData->m_nGLayer; }
			void set(short value) { m_pData->m_nGLayer = value; }
		};

		//属性フラグ
		property short m_sFlg {
			short get() { return m_pData->m_sFlg; }
			void set(short value) { m_pData->m_sFlg = value; }
		};

	internal:
		CData* m_pData;

	};

}