#pragma once
#include "CJwwWriter.h"
#include "JwwHeader.h"
#include "JwwData.h"
#include "JwwSen.h"
#include "JwwMoji.h"
#include "JwwTen.h"
#include "JwwEnko.h"
#include "JwwSunpou.h"
#include "JwwSolid.h"
#include "JwwBlock.h"
#include "JwwDataList.h"
#include "JwwImage.h"
using namespace System;
namespace JwwHelper {
	/// <summary>
	/// jwwファイル保存クラス。
	/// </summary>
	public ref class JwwWriter
	{
	public:
		/// <summary>
		/// ヘッダー
		/// </summary>
		property JwwHeader^ Header {
			JwwHeader^ get() {
				return _Header;
			}
		}
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		JwwWriter();
		/// <summary>
		/// ヘッダーは設定項目が多いのでjwwファイルにより初期化します。
		/// ヘッダー未初期化前はでたらめな値が入っています。必ず初期化してください。
		/// 初期化するファイルはver7.02以降にしてください(JW_DATA_VERSION=700)。
		/// 初期化後に希望するヘッダーのプロパティーを設定してください。
		/// </summary>
		/// <param name="templatePath">テンプレートファイルのパス</param>
		void InitHeader(String^ templatePath);

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
		/// <summary>
		/// 同梱画像を追加します。画像
		/// </summary>
		void AddImage(JwwImage^ image);
	public:
		~JwwWriter();
		!JwwWriter();

	private:
		CJwwWriter* m_pWriter;
		JwwHeader^ _Header;
		//array<JwwImage^>^ mImages = gcnew array<JwwImage^>(0);
	};
}
