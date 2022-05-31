#pragma once
#include "DataInfo.h"


class CDataManagement
{


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
	int ReadFileData(TCHAR cReadPath[MAX_PATH]);


	/// <summary>
	/// データの書き出しを実行
	/// </summary>
	/// <param name="cWritePath">書き出し先フォルダの親パス</param>
	/// <param name="cFileName">書き出し用のファイル名</param>
	/// <param name="cDataInfo">書き出し用データ</param>
	/// <returns>0：成功　0：以外失敗</returns>
	int WriteData(TCHAR cWritePath[MAX_PATH], TCHAR cFileName[_MAX_FNAME]);

	void GetDataInfo(CArray<CDataInfo*>& pacDataInfo);

	/// <summary>
	/// ファイル名を取得する
	/// </summary>
	/// <returns>ファイル名</returns>
	CString Getm_csFileName();

	/// <summary>
	/// 出力先パスを取得する
	/// </summary>
	/// <returns>出力先パス</returns>
	CString Getm_csReadPath();

	// 
	int CountCommaOcuurence(CString& cstr) const;


	//***********沓掛試し書き*********
	int ReadFileDataKK(TCHAR cReadPath[MAX_PATH]);
	int WriteDataKK(TCHAR cWritePath[MAX_PATH], TCHAR cFileName[_MAX_FNAME]);
	//********************************

// いずれはprivateにしたい
//private:
	// **********メンバ変数**********
	//CString m_csWritePath; // ファイル出力先親フォルダパス
	CString m_csFileName; // ファイル出力先ファイル名

	CString m_csReadPath; // 読み込むファイルの完全パス

	int m_nCount;
};