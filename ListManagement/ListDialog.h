#pragma once
#include "afxdialogex.h"


// CListDialog ダイアログ

class CListDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CListDialog)

public:
	CListDialog(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~CListDialog();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LISTDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
