
// ListManagement.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//


#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CListManagementApp:
// このクラスの実装については、ListManagement.cpp を参照してください
//

class CListManagementApp : public CWinApp
{
public:
	CListManagementApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CListManagementApp theApp;
