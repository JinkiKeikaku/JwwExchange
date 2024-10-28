#pragma once

using namespace System;
using namespace System::Collections::Generic;
#include "JwwClipHeader.h"
#include "JwwData.h"
#include "JwwDataList.h"
#include "CJwwClipReader.h"
#include "JwwImage.h"

namespace JwwHelper {
	public ref class JwwClipReader
	{
	public:
		delegate void CompletedCallback(JwwClipReader^);
	public:
		JwwClipReader() {
			m_pReader = new CJwwClipReader();
		}
		~JwwClipReader() { this->!JwwClipReader(); }
		!JwwClipReader() { delete m_pReader; }

	public:
		/// <summary>
		/// クリップボードデータのヘッダー
		/// </summary>
		property JwwClipHeader^ Header {
			JwwClipHeader^ get() { return mHeader; }
		};
		/// <summary>
		/// 図形のリスト
		/// </summary>
		property List<JwwData^>^ DataList {
			List<JwwData^>^ get() { return mDataList; }
		};
		/// <summary>
		/// ブロック図形実体のリスト
		/// </summary>
		property List<JwwDataList^>^ DataListList {
			List<JwwDataList^>^ get() { return mDataListList; }
		};

	public:
		void Read(array<byte>^ buffer, CompletedCallback^ completed);
		int GetBlockSize() {
			return mDataListList->Count;
		}

	protected:
		JwwClipHeader^ mHeader = gcnew JwwClipHeader();
		List<JwwData^>^ mDataList = gcnew List<JwwData^>();
		List<JwwDataList^>^ mDataListList = gcnew List<JwwDataList^>();

	protected:
		CJwwClipReader* m_pReader;
		void ConvertToManaged();


	};

}