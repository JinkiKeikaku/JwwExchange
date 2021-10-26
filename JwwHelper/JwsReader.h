#pragma once
using namespace System;
using namespace System::Collections::Generic;
#include "JwsHeader.h"
#include "JwwData.h"
#include "JwwDataList.h"
#include "CJwsReader.h"

namespace JwwHelper {
	public ref class JwsReader
	{
	public:
		delegate void CompletedCallback(JwsReader^);
	public:
		JwsReader(CompletedCallback^ completed, String^ imageFolder) {
			m_Completed = completed;
			if (imageFolder != nullptr) {
				pin_ptr<const WCHAR> str = PtrToStringChars(imageFolder);
				CW2A astr(str);
				m_pReader = new CJwsReader(astr);
			}
			else {
				m_pReader = new CJwsReader();
			}
		}
		~JwsReader() { this->!JwsReader(); }
		!JwsReader() { delete m_pReader; }
	public:
		property JwsHeader^ Header {
			JwsHeader^ get() { return mHeader; }
		};
		property List<JwwData^>^ DataList {
			List<JwwData^>^ get() { return mDataList; }
		};


	public:
		void Read(String^ path);
		int GetBlockSize() {
			return mDataListList->Count;
		}

	protected:
		JwsHeader^ mHeader = gcnew JwsHeader();
		List<JwwData^>^ mDataList = gcnew List<JwwData^>();
		List<JwwDataList^>^ mDataListList = gcnew List<JwwDataList^>();

	protected:
		CJwsReader* m_pReader;
		CompletedCallback^ m_Completed;
		void ConvertToManaged();

	};
}

