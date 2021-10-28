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
		JwsReader(CompletedCallback^ completed) {
			m_Completed = completed;
			m_pReader = new CJwsReader();
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
		property List<JwwDataList^>^ DataListList {
			List<JwwDataList^>^ get() { return mDataListList; }
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

