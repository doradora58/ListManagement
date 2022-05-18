
// ListManagementDlg.h : ヘッダー ファイル
//

#pragma once


// CListManagementDlg ダイアログ
class CListManagementDlg : public CDialogEx
{
// コンストラクション
public:
	CListManagementDlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LISTMANAGEMENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowWindow();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	// 読み取るCSVのパス
	CEdit ReadPath;
	// 結果（CSV読み取り関数の返り値）
	CEdit ReadResult;
	// CSVを書きこ出すパス
	CEdit WritePath;
	// 結果（書き込み関数の返り値）
	CEdit ResultWrite;
	// 書き出すCSVファイル名
	CEdit FileName;
};
