#pragma once

// 
enum ESex 
{
	MAN=0, // 男
	WOMAN, // 女
	OTHER //その他
};

// CSV読み込み構造体
struct TDataInfo
{
public:
	int nId; // ID
	CString csFirstName; // ファーストネーム
	CString csLastName; // ラストネーム
	int nAge; // 年齢
	ESex eSex; // 性別 
	int nHeight; // 身長
	int nWeight; // 体重
	CString csPlace; // 出身地

};

class CDataInfo
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CDataInfo();


	/// <summary>
	/// デストラクタ
	/// </summary>
	~CDataInfo();


};