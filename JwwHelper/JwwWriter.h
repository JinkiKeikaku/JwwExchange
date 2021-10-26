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
using namespace System;
namespace JwwHelper {

	public ref class JwwWriter
	{
	public:
		property JwwHeader^ Header {
			JwwHeader^ get() {
				return _Header;
			}
		}
	public:
		JwwWriter();
		/// <summary>
		/// ヘッダーは設定項目が多いのでjwwファイルにより初期化します。
		/// ヘッダー未初期化前はでたらめな値が入っています。必ず初期化してください。
		/// 初期化するファイルはver7.02以降にしてください(JW_DATA_VERSION=700)。
		/// 初期化後に希望するヘッダーのプロパティーを設定してください。
		/// </summary>
		/// <param name="templatePath">テンプレートファイルのパス</param>
		void InitHeader(String^ templatePath);
		void Write(String^ path);
		void AddData(JwwData^ data);
		void AddDataList(JwwDataList^ dataList);
	public:
		~JwwWriter();
		!JwwWriter();

	private:
		CJwwWriter* m_pWriter;
		JwwHeader^ _Header;
	};
}
