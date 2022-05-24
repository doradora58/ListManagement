// CListDialog.cpp : 実装ファイル
//

#include "pch.h"
#include "ListManagement.h"
#include "afxdialogex.h"
#include "ListDialog.h"
#include "DataManagement.h"


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


	CListCtrl* pListCtrl1 = (CListCtrl*)GetDlgItem(IDC_LIST1);	// GetDlgItemでリストコントロールIDC_LIST1のオブジェクトポインタをpListCtrl1に格納.((CListCtrl *)にキャスト.)
	// カラム1の挿入.
	LVCOLUMN lvCol[CSV_COLUMNS_NUM];	// カラム1
	for (int i = 7; i >= 0; i--)
	{
		lvCol[i].mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;	// 配置, ヘッダ名, 幅をセット.
		lvCol[i].fmt = LVCFMT_LEFT;		// 左寄せ.
		switch (i)
		{
		case 0:
			lvCol[i].pszText = _T("ID"); // 列名
			lvCol[i].cx = 30;	// 幅
			break;
		case 1:
			lvCol[i].pszText = _T("FirstName"); // 列名
			lvCol[i].cx = 70;	// 幅
			break;
		case 2:
			lvCol[i].pszText = _T("LastName"); // 列名
			lvCol[i].cx = 70;	// 幅
			break;
		case 3:
			lvCol[i].pszText = _T("Age"); // 列名
			lvCol[i].cx = 50;	// 幅
			break;	
		case 4:
			lvCol[i].pszText = _T("Sex"); // 列名
			lvCol[i].cx = 50;	// 幅
			break;
		case 5:
			lvCol[i].pszText = _T("Height"); // 列名
			lvCol[i].cx = 60;	// 幅
			break;
		case 6:
			lvCol[i].pszText = _T("Weight"); // 列名
			lvCol[i].cx = 60;	// 幅
			break;
		case 7:
			lvCol[i].pszText = _T("From"); // 列名
			lvCol[i].cx = 70;	// 幅
			break;
		default:
			break;
		}
		pListCtrl1->InsertColumn(0, &lvCol[i]);	// pListCtrl1->InsertColumnでカラムヘッダにlvCol1を挿入.

	}
	
	CDataInfo* pcData = new CDataInfo;


	// アイテム1_1～1_3の挿入.
	LVITEM lvItem1_1;	// アイテム1_1
	lvItem1_1.mask = LVIF_TEXT;	// アイテムテキストのみセット.
	lvItem1_1.pszText = _T("太郎");	// アイテムテキストは"Taro".
	lvItem1_1.iItem = 0;	// 0行
	lvItem1_1.iSubItem = 0;	// 0列
	pListCtrl1->InsertItem(&lvItem1_1);	// pListCtrl1->InsertItemでlvItem1_1を挿入.
	LVITEM lvItem1_2;	// アイテム1_2
	lvItem1_2.mask = LVIF_TEXT;	// アイテムテキストのみセット.
	lvItem1_2.pszText = _T("20");	// アイテムテキストは"20".
	lvItem1_2.iItem = 0;	// 0行
	lvItem1_2.iSubItem = 1;	// 1列
	pListCtrl1->SetItem(&lvItem1_2);	// pListCtrl1->SetItemでlvItem1_2を挿入.(正確にはセット.)
	LVITEM lvItem1_3;	// アイテム1_3
	lvItem1_3.mask = LVIF_TEXT;	// アイテムテキストのみセット.
	lvItem1_3.pszText = _T("Tokyo");	// アイテムテキストは"Tokyo".
	lvItem1_3.iItem = 0;	// 0行
	lvItem1_3.iSubItem = 2;	// 2列
	pListCtrl1->SetItem(&lvItem1_3);	// pListCtrl1->SetItemでlvItem1_3を挿入.(正確にはセット.)

}


BEGIN_MESSAGE_MAP(CListDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &CListDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CListDialog メッセージ ハンドラー


void CListDialog::OnBnClickedOk()
{
	//// TODO: ここにコントロール通知ハンドラー コードを追加します。
	////CDialogEx::OnOK();
	//// リストコントロールにカラム(列)ヘッダと各アイテム(行項目)挿入.
	//CListCtrl* pListCtrl1 = (CListCtrl*)GetDlgItem(IDC_LIST1);	// GetDlgItemでリストコントロールIDC_LIST1のオブジェクトポインタをpListCtrl1に格納.((CListCtrl *)にキャスト.)
	//// カラム1の挿入.
	//LVCOLUMN lvCol1;	// カラム1
	//lvCol1.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;	// 配置, ヘッダ名, 幅をセット.
	//lvCol1.fmt = LVCFMT_LEFT;		// 左寄せ.
	//lvCol1.pszText = _T("Name");	// ヘッダ名は"Name".
	//lvCol1.cx = 120;	// 幅は120.
	//pListCtrl1->InsertColumn(0, &lvCol1);	// pListCtrl1->InsertColumnでカラムヘッダにlvCol1を挿入.
}
