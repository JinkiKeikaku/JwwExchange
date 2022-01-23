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
	public:
		virtual String^ ToString() override {
			return gcnew  String(
				" G:" + m_lGroup + " PS:" + m_nPenStyle + " PC:" + m_nPenColor + " PW:" + m_nPenWidth +
				" L:" + m_nLayer + " GL:" + m_nGLayer + " F:" + m_sFlg);
		}
	public:
		/// <summary>
		/// 曲線属性番号
		/// </summary>
		property int m_lGroup {
			int get() { return m_pData->m_lGroup; }
			void set(int value) { m_pData->m_lGroup = value; }
		};

		/// <summary>
		/// 線種番号
		/// </summary>
		property byte m_nPenStyle {
			byte get() { return m_pData->m_nPenStyle; }
			void set(byte value) { m_pData->m_nPenStyle = value; }
		};

		/// <summary>
		/// 線⾊番号
		/// </summary>
		property short m_nPenColor {
			short get() { return m_pData->m_nPenColor; }
			void set(short value) { m_pData->m_nPenColor = value; }
		};

		/// <summary>
		/// 線幅
		/// </summary>
		property short m_nPenWidth {
			short get() { return m_pData->m_nPenWidth; }
			void set(short value) { m_pData->m_nPenWidth = value; }
		};

		/// <summary>
		/// レイヤ番号
		/// </summary>
		property short m_nLayer {
			short get() { return m_pData->m_nLayer; }
			void set(short value) { m_pData->m_nLayer = value; }
		};

		/// <summary>
		/// レイヤグループ番号
		/// </summary>
		property short m_nGLayer {
			short get() { return m_pData->m_nGLayer; }
			void set(short value) { m_pData->m_nGLayer = value; }
		};

		/// <summary>
		/// 属性フラグ
		/// </summary>
		property short m_sFlg {
			short get() { return m_pData->m_sFlg; }
			void set(short value) { m_pData->m_sFlg = value; }
		};

	internal:
		CData* Clone() {
			return m_pData->Clone();
		}
	internal:
		CData* m_pData;
	};

}