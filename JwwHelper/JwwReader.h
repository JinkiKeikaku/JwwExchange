#pragma once
using namespace System;
using namespace System::Collections::Generic;
#include "JwwHeader.h"
#include "JwwData.h"
#include "JwwDataList.h"
#include "JwwImage.h"
#include "CJwwReader.h"

namespace JwwHelper {
	public ref class JwwReader
	{
	public:
		delegate void CompletedCallback(JwwReader^);
	public:
		JwwReader(CompletedCallback^ completed) {
			m_Completed = completed;
			m_pReader = new CJwwReader();
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

		/// <summary>
		/// 画像同梱のデータ配列。画像は圧縮されている。詳細は本家の説明書を見てください。
		/// </summary>
		property array<JwwImage^>^ Images {
			array<JwwImage^>^ get() {
				return mImages;
			}
		}


	public:
		void Read(String^ path);
		int GetBlockSize() {
			return mDataListList->Count;
		}

	protected:
		JwwHeader^ mHeader = gcnew JwwHeader();
		List<JwwData^>^ mDataList = gcnew List<JwwData^>();
		List<JwwDataList^>^ mDataListList = gcnew List<JwwDataList^>();
		array<JwwImage^>^ mImages = gcnew array<JwwImage^>(0);
		CJwwReader* m_pReader;
		CompletedCallback^ m_Completed;

		void ConvertToManaged();
	};

}

