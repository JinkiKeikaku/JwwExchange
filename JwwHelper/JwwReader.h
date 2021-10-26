#pragma once
using namespace System;
using namespace System::Collections::Generic;
#include "JwwHeader.h"
#include "JwwData.h"
#include "JwwDataList.h"
#include "CJwwReader.h"

namespace JwwHelper {
	public ref class JwwReader
	{
	public:
		delegate void CompletedCallback(JwwReader^);
	public:
		JwwReader(CompletedCallback^ completed, String^ imageFolder) {
			m_Completed = completed;
			if (imageFolder != nullptr) {
				pin_ptr<const WCHAR> str = PtrToStringChars(imageFolder);
				CW2A astr(str);
				m_pReader = new CJwwReader(astr);
			}
			else {
				m_pReader = new CJwwReader();
			}
		}
		~JwwReader() { this->!JwwReader(); }
		!JwwReader() { delete m_pReader; }
	public:
		property JwwHeader^ Header {
			JwwHeader^ get() { return mHeader; }
		};
		property List<JwwData^>^ DataList {
			List<JwwData^>^ get() { return mDataList; }
		};
		property List<JwwDataList^>^ DataListList {
			List<JwwDataList^>^ get() { return mDataListList; }
		};


	public:
		void Read(String^ path);
		int GetBlockSize() {
			return mDataListList->Count;
		}

	protected:
		JwwHeader^ mHeader = gcnew JwwHeader();
		List<JwwData^>^ mDataList = gcnew List<JwwData^>();
		List<JwwDataList^>^ mDataListList = gcnew List<JwwDataList^>();

	protected:
		CJwwReader* m_pReader;
		CompletedCallback^ m_Completed;
		void ConvertToManaged();
	};
}

