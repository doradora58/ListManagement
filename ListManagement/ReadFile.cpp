#include "pch.h"
#include "ReadFile.h"
#include "DataInfo.h"

CArray <CDataInfo*>* m_patDataInfoList = nullptr;

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
	// 入力ファイルが存在するか確認
	if (cFileFind.FindFile(csReadPath) == 0) // FindFile関数の戻り値が0以外で正常完了
	{
		return NOT_FOUND_FILE;
	}

	CStdioFile cFile;
	cFile.Open(csReadPath, CFile::modeRead);
	// 一行分テキスト読み込み
	CString csReadLineText;
	cFile.ReadString(csReadLineText);
	cFile.Close();
	return 0;
}
