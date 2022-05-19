#include "pch.h"
#include "WriteFile.h"
#include "DataInfo.h"
#include "ReadFile.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="cWritePath">CSV書き出し用のパス</param>
CWriteFile::CWriteFile(wchar_t cWritePath[MAX_PATH],wchar_t cFileName[_MAX_FNAME])
{
	m_csWritePath = cWritePath;
	m_csFileName = cFileName;
}


/// <summary>
/// デスストラクタ
/// </summary>
CWriteFile::~CWriteFile()
{
	m_csWritePath = "";
	m_csFileName = "";
}
/// <summary>
/// ファイルにデータの書き出しを実行
/// </summary>
/// <param name="cWritePath">書き出し先フォルダのパス</param>
/// <param name="cFileName">書き出し用のファイル名</param>
/// <param name="cDataInfo">書き出し用データ</param>
/// <returns>0：成功　0：以外失敗</returns>
int CWriteFile::WriteData(wchar_t cWritePath[MAX_PATH], wchar_t cFileName[_MAX_FNAME], TDataInfo tDataInfo)
{
	CString csWritePath = CString(cWritePath) + _T("\\") + CString(cFileName);
	// インスタンスの生成
	CStdioFile cStdioFile;
	// データ出力先ファイルをオープン
	cStdioFile.Open(csWritePath, CFile::modeReadWrite | CFile::shareDenyNone | CFile::modeCreate | CFile::modeNoTruncate);
	// ファイルの最後にアタッチ
	cStdioFile.SeekToEnd();
	// ファイルにデータを書き込む
	CString csId;
	csId.Format(_T("%s"), tDataInfo.nId + ",");
	cStdioFile.WriteString(csId);
	cStdioFile.WriteString((CString)tDataInfo.csFirstName + _T(","));
	cStdioFile.WriteString(tDataInfo.csLastName + _T(","));
	CString csAge;
	csAge.Format(_T("%d"), tDataInfo.nAge + _T(","));
	cStdioFile.WriteString(csAge + _T(","));
	CString csSex;
	csSex.Format(_T("%d"), tDataInfo.eSex + _T(","));
	cStdioFile.WriteString(csSex + _T(","));
	CString csHeight;
	csSex.Format(_T("%d"), tDataInfo.nHeight + _T(","));
	cStdioFile.WriteString(csHeight);
	CString csWeight;
	csWeight.Format(_T("%d"), tDataInfo.nWeight + _T(","));
	cStdioFile.WriteString(csWeight + _T(","));
	cStdioFile.WriteString(tDataInfo.csFrom + _T(","));




	return 0;
}

