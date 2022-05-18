#pragma once
#include "DataInfo.h"

#define MAX_TEXT 100 // テキストの最大値

// CSVファイル書き出しクラス
class CWriteFile
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="cWritePath">CSV書き出し用のパス</param>
	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="cWritePath"></param>
	/// <param name="cFIleName"></param>
	CWriteFile(wchar_t cWritePath[MAX_PATH], wchar_t cFIleName[_MAX_FNAME]);

	/// <summary>
	/// デスストラクタ
	/// </summary>
	~CWriteFile();

	/// <summary>
	/// CSVの書き出しを実行
	/// </summary>
	/// <param name="cWritePath">書き出し先フォルダの親パス</param>
	/// <param name="cFileName">書き出し用のファイル名</param>
	/// <param name="cText">書き出し内容</param>
	/// <returns>0：成功　0：以外失敗</returns>
	int WriteCsvText(wchar_t cWritePath[MAX_PATH], wchar_t cFileName[_MAX_FNAME],wchar_t cText[MAX_TEXT]);




	// **********メンバ変数**********
	CString m_csWritePath; // ファイル出力先親フォルダパス
	CString m_csFileName; // ファイル出力先ファイル名



};