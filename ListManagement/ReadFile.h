#pragma once

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



	// **********メンバ変数**********

	CString m_csReadPath; // 読み込むファイルの完全パス

};