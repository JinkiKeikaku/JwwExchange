#pragma once
#include "CJwwClipWriter.h"
#include "JwwClipHeader.h"
#include "JwwData.h"
#include "JwwDataList.h"

using namespace System;
namespace JwwHelper {

	public ref class JwwClipWriter
	{
	public:
		/// <summary>
		/// ヘッダー
		/// </summary>
		property JwwClipHeader^ Header {
			JwwClipHeader^ get() {
				return _Header;
			}
		}
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		JwwClipWriter();
		/// <summary>
		/// 書き出し
		/// </summary>
		/// <param name="path"></param>
		IntPtr Write();
		/// <summary>
		/// 書き込む図形を追加します。
		/// </summary>
		/// <param name="data"></param>
		void AddData(JwwData^ data);
		/// <summary>
		/// ブロック図形の実体を追加します。
		/// </summary>
		void AddDataList(JwwDataList^ dataList);
	public:
		~JwwClipWriter();
		!JwwClipWriter();

	private:
		CJwwClipWriter* m_pWriter;
		JwwClipHeader^ _Header;

	};
}
