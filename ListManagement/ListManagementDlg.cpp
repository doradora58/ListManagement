
// ListManagementDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "ListManagement.h"
#include "ListManagementDlg.h"
#include "afxdialogex.h"
#include "DataInfo.h"
#include "DataManagement.h"
#include "ListDialog.h"
#include "Library.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




extern CArray<CDataInfo*>* m_pacDataInfo;

// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CListManagementDlg ダイアログ



CListManagementDlg::CListManagementDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LISTMANAGEMENT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListManagementDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, ReadPath);
	DDX_Control(pDX, IDC_EDIT5, ReadResult);
	DDX_Control(pDX, IDC_EDIT3, WritePath);
	DDX_Control(pDX, IDC_EDIT6, ResultWrite);
	DDX_Control(pDX, IDC_EDIT4, FileName);
	DDX_Control(pDX, IDC_EDIT2, Count);
}

BEGIN_MESSAGE_MAP(CListManagementDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CListManagementDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CListManagementDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CListManagementDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_DELETEBUTTON, &CListManagementDlg::OnBnClickedDeletebutton)
END_MESSAGE_MAP()


// CListManagementDlg メッセージ ハンドラー

BOOL CListManagementDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	
	CParam* cParam = new CParam;
	CParam:: pParam = cParam;

	std::string filePath = "..\\x64\\Debug\\config.ini";
	//std::string filePath = "C:\\Users\\27114\\source\\repos\\ListManagement\\x64\\Debug\\config.ini";
	std::string a = cParam->GetConfigString(filePath, "System", "WindowText");
	cParam->m_csLogPath = a.c_str();
	OnShowWindow();

	CONTVALINVAL(IDC_DELETEBUTTON);
	CONTVALINVAL(IDC_BUTTON3);
	CONTVALINVAL(IDC_BUTTON2);

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CListManagementDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CListManagementDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CListManagementDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 初期値の設定(アプリ起動時に実行）
void CListManagementDlg::OnShowWindow()
{
	// 読み込み用CSVファイルのパス
	CString csReadPath;
	// 書き出し用ファイルのパス
	CString csWritePath;
	// 書き出し用CSVのファイル名
	CString csFileName = _T("OutputData.csv");
	// ドライブ名、ディレクトリ名、ファイル名、拡張子
	TCHAR path[_MAX_PATH], drive[_MAX_PATH], dir[_MAX_PATH], fname[_MAX_PATH], ext[_MAX_PATH];

	// 実行ファイルのファイルパスを取得
	if (::GetModuleFileName(NULL, path, _MAX_PATH) != 0)
	{
		// ファイルパスを分割
		::_splitpath_s(path, drive, dir, fname, ext);

		CString dir2 = dir;

		// 入力、出力パスの結合
		CString root = _T("\\ListManagement");
		csReadPath = CString(drive) + dir2.Left(dir2.Find(root)) + _T("\\ListManagement\\ListManagement\\Document\\Input\\Data.csv");
		csWritePath = CString(drive) + dir2.Left(dir2.Find(root)) + _T("\\ListManagement\\ListManagement\\Document\\Output");

	}
	this->ReadPath.SetWindowText(csReadPath);
	this->WritePath.SetWindowText(csWritePath);
	this->FileName.SetWindowText(csFileName);

}

// CSV読み取り関数の実行
void CListManagementDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	// 読み込みパスの取得
	CString csReadPath;
	this->ReadPath.GetWindowText(csReadPath);
	TCHAR* cReadPath = csReadPath.GetBuffer();

	CDataManagement cDataManagement;

//	int b = cDataManagement.ReadFileData(cReadPath);
	int	b = cDataManagement.ReadFileDataKK(cReadPath);
	CString csResult;
	csResult.Format(_T("%d"), b);
	this->ReadResult.SetWindowText(csResult);
	CONTVALINVAL(IDC_DELETEBUTTON);
	CONTVALINVAL(IDC_BUTTON3);
	CONTVALINVAL(IDC_BUTTON2);
}

// CSV書き込み関数の実行
void CListManagementDlg::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	// 書き込みパスの取得
	CString csWritePath;
	this->WritePath.GetWindowText(csWritePath);
	TCHAR* cWritePath = csWritePath.GetBuffer();

	// 書き込み用ファイル名の取得
	CString csFileName;
	this->FileName.GetWindowText(csFileName);
	TCHAR* cFileName = csFileName.GetBuffer();

	CDataManagement cDataManagement;
	int b = cDataManagement.WriteData(cWritePath, cFileName);
	CString csResult;
	csResult.Format(_T("%d"), b);
	this->ResultWrite.SetWindowText(csResult);
}


void CListManagementDlg::OnBnClickedButton3()
{
	if (m_pacDataInfo != nullptr)
	{
		CListDialog CListDialog;
		CListDialog.DoModal();
	}

	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}


void CListManagementDlg::OnBnClickedDeletebutton()
{
	if (m_pacDataInfo != nullptr)
	{
		for (int i = 0; i < m_pacDataInfo->GetCount(); i++)
		{
			CDataInfo* pDdataInfo = m_pacDataInfo->GetAt(i);
			delete pDdataInfo;
		}
		m_pacDataInfo->RemoveAll();
		delete m_pacDataInfo;
		m_pacDataInfo = nullptr;
		CDataInfo::ResetItemNum();
	}

	CONTVALINVAL(IDC_DELETEBUTTON);
	CONTVALINVAL(IDC_BUTTON3);
	CONTVALINVAL(IDC_BUTTON2);

	// TODO: ここにコントロール通知ハンドラー コードを追加します。

}
