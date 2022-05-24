// CListDialog.cpp : 実装ファイル
//

#include "pch.h"
#include "ListManagement.h"
#include "afxdialogex.h"
#include "ListDialog.h"


// CListDialog ダイアログ

IMPLEMENT_DYNAMIC(CListDialog, CDialogEx)

CListDialog::CListDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LISTDIALOG, pParent)
{

}

CListDialog::~CListDialog()
{
}

void CListDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CListDialog, CDialogEx)
END_MESSAGE_MAP()


// CListDialog メッセージ ハンドラー
