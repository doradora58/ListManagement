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

	//CListCtrl* pListCtrl1 = (CListCtrl*)GetDlgItem(IDC_LIST1);	// GetDlgItemでリストコントロールIDC_LIST1のオブジェクトポインタをpListCtrl1に格納.((CListCtrl *)にキャスト.)
	
	CArray<CDataInfo*> acDataInfo;
	CDataManagement cDataManagement;
	cDataManagement.GetDataInfo(acDataInfo);

	// リストコントロールにカラム(列)ヘッダと各アイテム(行項目)挿入.
	CListCtrl* pListCtrl1 = (CListCtrl*)GetDlgItem(IDC_LIST1);	// GetDlgItemでリストコントロールIDC_LIST1のオブジェクトポインタをpListCtrl1に格納.((CListCtrl *)にキャスト.)
	
	// カラム1の挿入.
	LVCOLUMN lvCol[CSV_COLUMNS_NUM];	// カラム1
	for (int i = 0; i < CSV_COLUMNS_NUM ; i++)
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
			for (int i = 0; i < acDataInfo.GetCount(); i++)
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
			pListCtrl1->InsertColumn(i, &lvCol[i]);	// pListCtrl1->InsertColumnでカラムヘッダにlvCol1を挿入.
	}
	CString csId;
	CString csAge;
	CString csHeight;
	CString csSex;
	CString csWeight;
	CString csFrom;

	for (int j = 0; j < acDataInfo.GetCount(); j++) 
	{
		for (int i = 0; i < CSV_COLUMNS_NUM; i++)
		{

			LVITEM lyItem[CSV_COLUMNS_NUM];
			lyItem[i].mask = LVIF_TEXT;	// アイテムテキストのみセット.
			lyItem[i].pszText = _T("Taro");	// アイテムテキストは"Taro".
			lyItem[i].iItem = j;	// 0行
			lyItem[i].iSubItem = i;	// 0列

			switch (i)
			{
			case 0:
				lyItem[i].iSubItem = i;	// 0列
				csId.Format(_T("%d"), acDataInfo.ElementAt(j)->m_nId);
				lyItem[i].pszText = csId.GetBuffer(); // 列名
				pListCtrl1->InsertItem(&lyItem[i]);
				
				break;
			case 1:
				lyItem[i].iSubItem = i;	// 0列
				lyItem[i].pszText = acDataInfo.ElementAt(j)->m_csFirstName.GetBuffer();
				pListCtrl1->SetItem(&lyItem[i]);
				
				break;
			case 2:
				lyItem[i].iSubItem = i;	// 0列
				lyItem[i].pszText = acDataInfo.ElementAt(j)->m_csLastName.GetBuffer();
				pListCtrl1->SetItem(&lyItem[i]);
				
				break;
			case 3:
				lyItem[i].iSubItem = i;	// 0列				
				csAge.Format(_T("%d"), acDataInfo.ElementAt(j)->m_nAge);
				lyItem[i].pszText = csAge.GetBuffer(); // 列名
				pListCtrl1->SetItem(&lyItem[i]);
				
				break;
			case 4:
				lyItem[i].iSubItem = i;	// 0列
				switch (acDataInfo.ElementAt(j)->m_eSex)
				{
				case ESex::MAN:
						lyItem[i].pszText = _T("男");
						break;
				case ESex::WOMAN:
						lyItem[i].pszText = _T("女");
						break;
				case ESex::OTHER:
						lyItem[i].pszText = _T("その他");
						break;
				}
				pListCtrl1->SetItem(&lyItem[i]);
				
				break;
			case 5:
				lyItem[i].iSubItem = i;	// 0列
				csHeight.Format(_T("%d"), acDataInfo.ElementAt(j)->m_nHeight);
				lyItem[i].pszText = csHeight.GetBuffer(); // 列名
				pListCtrl1->SetItem(&lyItem[i]);
				
				break;
			case 6:
				lyItem[i].iSubItem = i;	// 0列
				csWeight.Format(_T("%d"), acDataInfo.ElementAt(j)->m_nWeight);
				lyItem[i].pszText = csWeight.GetBuffer(); // 列名
				pListCtrl1->SetItem(&lyItem[i]);
				
				break;
			case 7:
				lyItem[i].iSubItem = i;	// 0列
				lyItem[i].pszText = acDataInfo.ElementAt(j)->m_csFrom.GetBuffer();
				pListCtrl1->SetItem(&lyItem[i]);
			
				break;
			default:
				break;
			}
		}

	}

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
