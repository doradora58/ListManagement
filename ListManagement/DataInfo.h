#pragma once

// 
enum ESex 
{
	MAN=0, // 男
	WOMAN, // 女
	OTHER //その他
};

// データ情報構造体
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
	CString csFrom; // 出身地
	TDataInfo()
	{
		nId = 0;
		csFirstName = "";
		csLastName = "";
		nAge = 0;
		eSex = ESex::MAN;
		nHeight = 0;
		nWeight = 0;
		csFrom = "";

	}

};

// データ情報クラス
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

	void SetFirstName(CString csFirstName);

	void GetData(int* nId, CString* csFirstName, CString* csLastName, int* nAge, ESex* eSex, int* nHeight, int* nWeight, CString* csFrom);

	int m_nId; // ID
	CString m_csFirstName; // ファーストネーム
	CString m_csLastName; // ラストネーム
	int m_nAge; // 年齢
	ESex m_eSex; // 性別 
	int m_nHeight; // 身長
	int m_nWeight; // 体重
	CString m_csFrom; // 出身地
};