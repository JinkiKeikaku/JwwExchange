#pragma once
#include "CDataList.h"
#include "JwwData.h"
#include "JwwUtility.h"

using namespace System;

namespace JwwHelper {

	/// <summary>
	/// ブロック図形の実体図形のリスト
	/// </summary>
	public ref class JwwDataList : public JwwData
	{
	public:
		/// <summary>
		/// DataListの図形を取得するために使う。
		/// </summary>
		delegate bool EnumerateShapeCallback(JwwData^);
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		JwwDataList() : JwwData(new CDataList(), false){
		}
	internal:
		JwwDataList(CDataList* pDataList) : JwwData(pDataList, false) {
		}
		property CDataList* m_pDataList {
			CDataList* get() { return (CDataList*)m_pData; }
		}
	public:

		/// <summary>
		/// 定義データの通し番号
		/// </summary>
		property short m_nNumber {
			short get() { return m_pDataList->m_nNumber; }
			void set(short value) { m_pDataList->m_nNumber = value; }
		};

		/// <summary>
		/// 参照されているかのフラグ
		/// </summary>
		property bool m_bReffered {
			bool get() { return m_pDataList->m_bReffered; }
			void set(bool value) { m_pDataList->m_bReffered = value; }
		};

		/// <summary>
		/// 定義された時間
		/// </summary>
		property DateTime^ m_time {
			DateTime^ get() { return  gcnew DateTime(
					m_pDataList->m_time.GetYear(), m_pDataList->m_time.GetMonth(), m_pDataList->m_time.GetDay(),
					m_pDataList->m_time.GetHour(), m_pDataList->m_time.GetMinute(), m_pDataList->m_time.GetSecond()
				);
			}

			void set(DateTime^ value) { 
				m_pDataList->m_time = CTime(
					m_time->Year, m_time->Month, m_time->Day,
					m_time->Hour, m_time->Month, m_time->Second
				);
			}
		};

		/// <summary>
		/// 定義データの名前
		/// </summary>
		property String^ m_strName {
			String^ get() { return gcnew String(CA2W(m_pDataList->m_strName.GetString())); }
			void set(String^ value) { 
				pin_ptr<const WCHAR> str = PtrToStringChars(value);
				CW2A astr(str);
				m_pDataList->m_strName = astr;
			}
		};

		/// <summary>
		/// ブロック図形内の図形数を返します。
		/// </summary>
		int GetSize() {
			return m_pDataList->m_DataList.GetCount();
		}

		/// <summary>
		/// ブロック図形の図形要素を列挙します。[callback]がfalseを返すと列挙を中止します。
		/// </summary>
		/// <param name="callback"></param>
		/// <returns>列挙が中止されるとfalseを返します。</returns>
		bool EnumerateDataList(EnumerateShapeCallback^ callback) {
			POSITION pos = m_pDataList->m_DataList.GetHeadPosition();
			bool flag = true;
			while (pos != NULL && flag) {
				CData* data = m_pDataList->m_DataList.GetNext(pos);
				JwwData^ jd = ConvertToJwwData(data);
				if (jd != nullptr) {
					flag = callback(jd);
				}
			}
			return flag;
		}

		/// <summary>
		/// 図形を追加。
		/// </summary>
		void Add(JwwData^ data) {
			m_pDataList->m_DataList.AddHead(data->Clone());
		}
	};
}
