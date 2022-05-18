#include "pch.h"
#include "ReadFile.h"
#include "DataInfo.h"

CArray <TDataInfo*>* m_patDataInfoList = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
CReadFile::CReadFile()
{

}

/// <summary>
/// デストラクタ
/// </summary>
CReadFile::~CReadFile()
{
}

int CReadFile::ReadFileData(wchar_t cReadPath[MAX_PATH])
{
	CString csReadPath = cReadPath;
	// インスタンスの生成
	CFileFind cFileFind;
	//
	CDataInfo cDataInfo;
	// 入力ファイルが存在するか確認
	if (cFileFind.FindFile(csReadPath) == 0) // FindFile関数の戻り値が0以外で正常完了
	{
		return NOT_FOUND_FILE;
	}



	CStdioFile cFile;
	cFile.Open(csReadPath, CFile::modeRead);
	// 一行分テキスト読み込み
	CString csReadLineText;
	while (cFile.ReadString(csReadLineText))
	{
		// 先頭文字位置
		int nStart = 0;
		// 
		int nPos = -1; 
		nPos = csReadLineText.Find(',', nStart);
//		m_patDataInfoList->ElementAt(0).nId = (int)csReadLineText.Mid(nStart, nPos - nStart);
	}
	cFile.Close();
	return 0;
}
