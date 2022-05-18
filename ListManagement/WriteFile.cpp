#include "pch.h"
#include "WriteFile.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="cWritePath">CSV書き出し用のパス</param>
CWriteFile::CWriteFile(wchar_t cWritePath[MAX_PATH],wchar_t cFileName[_MAX_FNAME])
{

	m_csWritePath = cWritePath;

}


/// <summary>
/// デスストラクタ
/// </summary>
CWriteFile::~CWriteFile()
{
}

/// <summary>
/// CSVの書き出しを実行
/// </summary>
/// <param name="cWritePath">書き出し先フォルダの親パス</param>
/// <param name="cFileName">書き出し用のファイル名</param>
/// <param name="cText">書き出し内容</param>
/// <returns>0：成功　0：以外失敗</returns>
int CWriteFile::WriteCsvText(wchar_t cWritePath[MAX_PATH], wchar_t cFileName[_MAX_FNAME], wchar_t cText[MAX_TEXT])
{

	return 0;
}
