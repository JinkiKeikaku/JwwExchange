#pragma once
#include "CDataList.h"
//#include "JwwData.h"
#include "JwwUtility.h"

using namespace System;

namespace JwwHelper {
	public ref class JwwDataList : public JwwData
	{
	public:
		/// <summary>
		/// DataList‚Ì}Œ`‚ğæ“¾‚·‚é‚½‚ß‚Ég‚¤B
		/// </summary>
		delegate bool EnumerateShapeCallback(JwwData^);
	internal:
		JwwDataList() : JwwData(new CDataList(), false){
		}
		JwwDataList(CDataList* pDataList) : JwwData(pDataList, false) {
		}
	public:
		property short m_nNumber {
			short get() { return m_pData->m_nNumber; }
			void set(short value) { m_pData->m_nNumber = value; }
		};
		property bool m_bReffered {
			bool get() { return m_pData->m_bReffered; }
			void set(bool value) { m_pData->m_bReffered = value; }
		};

		property DateTime^ m_time {
			DateTime^ get() { return  gcnew DateTime(
					m_pData->m_time.GetYear(), m_pData->m_time.GetMonth(), m_pData->m_time.GetDay(),
					m_pData->m_time.GetHour(), m_pData->m_time.GetMinute(), m_pData->m_time.GetSecond()
				);
			}

			void set(DateTime^ value) { 
				m_pData->m_time = CTime(
					m_time->Year, m_time->Month, m_time->Day,
					m_time->Hour, m_time->Month, m_time->Second
				);
			}
		};

		property String^ m_strName {
			String^ get() { return gcnew String(CA2W(m_pData->m_strName.GetString())); }
			void set(String^ value) { 
				pin_ptr<const WCHAR> str = PtrToStringChars(value);
				CW2A astr(str);
				m_pData->m_strName = astr;
			}
		};

		bool EnumerateDataList(EnumerateShapeCallback^ callback) {
			POSITION pos = m_pData->m_DataList.GetHeadPosition();
			bool flag = true;
			while (pos != NULL && flag) {
				CData* data = m_pData->m_DataList.GetNext(pos);
				JwwData^ jd = ConvertToJwwData(data);
				if (jd != nullptr) {
					flag = callback(jd);
				}
			}
			return flag;
		}


	internal:
		CDataList* m_pData;
	};
}
