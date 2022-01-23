#pragma once
using namespace System;
using namespace System::Collections::Generic;
#include "JwwHeader.h"
#include "JwwData.h"
#include "JwwDataList.h"
#include "JwwImage.h"
#include "CJwwReader.h"

namespace JwwHelper {
	/// <summary>
	/// jwwファイル読み込みクラス
	/// </summary>
	public ref class JwwReader
	{
	public:
		/// <summary>
		/// ファイル読み込み完了時に呼ばれるコールバック
		/// </summary>
		delegate void CompletedCallback(JwwReader^);
	public:
		/// <summary>
		/// コンストラクタ。
		/// </summary>
		JwwReader() {
//			m_Completed = completed;
			m_pReader = new CJwwReader();
		}
		~JwwReader() { this->!JwwReader(); }
		!JwwReader() { delete m_pReader; }
	public:
		/// <summary>
		/// jwwファイルのヘッダー
		/// </summary>
		property JwwHeader^ Header {
			JwwHeader^ get() { return mHeader; }
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

		/// <summary>
		/// 画像同梱のデータ配列。画像は圧縮されている。詳細は本家のドキュメントを見てください。
		/// </summary>
		property array<JwwImage^>^ Images {
			array<JwwImage^>^ get() {
				return mImages;
			}
		}


	public:
		/// <summary>
		/// ファイル読み込み。読み込み完了時は渡したコールバックが呼ばれる。
		/// </summary>
		/// <param name="path"></param>
		void Read(String^ path, CompletedCallback^ completed);
		/// <summary>
		/// ブロック図形数。
		/// </summary>
		int GetBlockSize() {
			return mDataListList->Count;
		}

	protected:
		JwwHeader^ mHeader = gcnew JwwHeader();
		List<JwwData^>^ mDataList = gcnew List<JwwData^>();
		List<JwwDataList^>^ mDataListList = gcnew List<JwwDataList^>();
		array<JwwImage^>^ mImages = gcnew array<JwwImage^>(0);
		CJwwReader* m_pReader;
//		CompletedCallback^ m_Completed;

		void ConvertToManaged();
	};

}

