#pragma once

#include <Windows.h>  // GetPrivateProfileString
#include <iostream>      // cout
#include <array>     // array
#include <string>        // string

#define NOT_FOUND_FILE -1 // 入力ファイルが存在しないエラー
#define FILE_OPEN_FAILED -2 // ファイルが見つからないエラー
#define CSV_COLUMNS_NUM 8 // csvファイルの列数
#define SUCCESS 0 // 処理成功
#define NO_CSV_DATA -3 // CSVデータがないためエラー
#define NO_DATAINFO -4 // データ情報にデータがないためエラー
#define CSV_FORMAT_ERROR -5 // csvファイルのフォーマットエラー

// ボタンの有効／無効化
#define CONTVALINVAL(id) \
{CButton* button = (CButton*)GetDlgItem(id); \
button->EnableWindow(m_pacDataInfo != nullptr);}


// ログの定義
#define LOG(LogText,SourceFileName,SourceLine,FunctionName) \
{HINSTANCE hDLL;\
hDLL = LoadLibrary("Log.dll");\
int (*func)(TCHAR cDirPath[MAX_PATH], TCHAR cLogFileName[_MAX_FNAME], int& nIndex, int nFormatType);\
int (*funca)(int nIndex, TCHAR szLogText[100], TCHAR szSourceFileName[_MAX_FNAME], int nSourceLine, TCHAR szFunctionName[_MAX_FNAME]);\
(func = (int (*)(char cDirPath[MAX_PATH], char cLogFileName[_MAX_FNAME], int& nIndex, int nFormatType))GetProcAddress(hDLL, "SetOutputDirPath"));\
(funca = (int (*)(int nIndex, TCHAR szLogText[100], TCHAR szSourceFileName[_MAX_FNAME], int nSourceLine, TCHAR szFunctionName[_MAX_FNAME]))GetProcAddress(hDLL, "WriteLog"));\
int i=0;\
func(CParam::pParam->m_csLogPath.GetBuffer(), _T("ListManagement"), i, 0);\
/*func(_T("C:\\Users\\27114\\source\\repos\\ListManagement\\ListManagement\\Document\\Input"), _T("ListManagement"), i, 0);*/ \
funca(i, LogText, SourceFileName,SourceLine,FunctionName);\
FreeLibrary(hDLL);};


class CParam 
{
public:
	/// <summary>
	/// .iniファイル読み込み
	/// </summary>
	/// <param name="csFilePath">.iniファイルのパス</param>
	/// <param name="pSectionName">セクション名</param>
	/// <param name="pKeyName">キー名</param>
	/// <returns></returns>
	std::string GetConfigString(const std::string& filePath, const char* pSectionName, const char* pKeyName);


	CString m_csLogPath;


	static CParam* pParam;
};

