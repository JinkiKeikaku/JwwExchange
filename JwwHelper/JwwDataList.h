#pragma once
#include "CDataList.h"
#include "JwwData.h"
#include "JwwUtility.h"

using namespace System;

namespace JwwHelper {
	public ref class JwwDataList : public JwwData
	{
	public:
		/// <summary>
		/// DataListの図形を取得するために使う。
		/// </summary>
		delegate bool EnumerateShapeCallback(JwwData^);
	internal:
		JwwDataList() : JwwData(new CDataList(), false){
		}
		JwwDataList(CDataList* pDataList) : JwwData(pDataList, false) {
		}
		property CDataList* m_pDataList {
			CDataList* get() { return (CDataList*)m_pData; }
		}
	public:
		property short m_nNumber {
			short get() { return m_pDataList->m_nNumber; }
			void set(short value) { m_pDataList->m_nNumber = value; }
		};
		property bool m_bReffered {
			bool get() { return m_pDataList->m_bReffered; }
			void set(bool value) { m_pDataList->m_bReffered = value; }
		};

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

		property String^ m_strName {
			String^ get() { return gcnew String(CA2W(m_pDataList->m_strName.GetString())); }
			void set(String^ value) { 
				pin_ptr<const WCHAR> str = PtrToStringChars(value);
				CW2A astr(str);
				m_pDataList->m_strName = astr;
			}
		};

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
	};
}
