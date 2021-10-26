// JwwHelper.h : JwwHelper DLL のメイン ヘッダー ファイル
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CJwwHelperApp
// このクラスの実装に関しては JwwHelper.cpp をご覧ください
//

class CJwwHelperApp : public CWinApp
{
public:
	CJwwHelperApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


