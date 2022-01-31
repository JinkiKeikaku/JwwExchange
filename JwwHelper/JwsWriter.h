#pragma once
#include "CJwsWriter.h"
#include "JwsHeader.h"
#include "JwwData.h"
#include "JwwDataList.h"

using namespace System;
namespace JwwHelper {

	/// <summary>
	/// jwsファイル保存クラス。
	/// </summary>
	public ref class JwsWriter
	{
	public:
		/// <summary>
		/// ヘッダー
		/// </summary>
		property JwsHeader^ Header {
			JwsHeader^ get() {
				return _Header;
			}
		}
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		JwsWriter();
		/// <summary>
		/// ファイル書き出し
		/// </summary>
		/// <param name="path"></param>
		void Write(String^ path);
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
		~JwsWriter();
		!JwsWriter();

	private:
		CJwsWriter* m_pWriter;
		JwsHeader^ _Header;

	};

}
