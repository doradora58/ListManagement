#pragma once
#include "DataInfo.h"

class CDataManagement {


public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CDataManagement();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~CDataManagement();


	/// <summary>
	/// csvファイルの読み込み実行関数
	/// </summary>
	/// <param name="cReadPath">読み込みパス</param>
	/// <returns>0:成功　0以外:失敗</returns>
	int ReadFileData(wchar_t cReadPath[MAX_PATH]);


	/// <summary>
	/// データの書き出しを実行
	/// </summary>
	/// <param name="cWritePath">書き出し先フォルダの親パス</param>
	/// <param name="cFileName">書き出し用のファイル名</param>
	/// <param name="cDataInfo">書き出し用データ</param>
	/// <returns>0：成功　0：以外失敗</returns>
	int WriteData(wchar_t cWritePath[MAX_PATH], wchar_t cFileName[_MAX_FNAME], TDataInfo tDataInfo);




	// **********メンバ変数**********
	CString m_csWritePath; // ファイル出力先親フォルダパス
	CString m_csFileName; // ファイル出力先ファイル名

	CString m_csReadPath; // 読み込むファイルの完全パス
	TDataInfo* m_ptDataInfo;

};