#pragma once
#include "DataInfo.h"

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




	// **********メンバ変数**********
	CString m_csWritePath; // ファイル出力先親フォルダパス
	CString m_csFileName; // ファイル出力先ファイル名



};