#pragma once
#define NOT_FOUND_FILE -1 // 入力ファイルが存在しないエラー

// csv読み込みクラス
class CReadFile
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CReadFile();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~CReadFile();


	/// <summary>
	/// csvファイルの読み込み実行関数
	/// </summary>
	/// <param name="cReadPath">読み込みパス</param>
	/// <returns>0:成功　0以外:失敗</returns>
	int ReadFileData(wchar_t cReadPath[MAX_PATH]);



	// **********メンバ変数**********

	CString m_csReadPath; // 読み込むファイルの完全パス

};