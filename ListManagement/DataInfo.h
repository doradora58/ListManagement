#pragma once

// 
enum ESex
{
	MAN = 0, // 男
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
		eSex = ESex::OTHER;
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

	//void SetData(CString nId, CString csFirstName, CString csLastName, CString nAge, CString eSex, CString nHeight, CString nWeight, CString csFrom);

	//void SetData(TDataInfo tDataInfo);

	// 
	void SetData(CStringArray* cstringarrayList);

	void GetData(int* nId, CString* csFirstName, CString* csLastName, int* nAge, ESex* eSex, int* nHeight, int* nWeight, CString* csFrom);

	void GetData(TDataInfo* ptDataInfo);

	// m_snItemNumのSet関数
	static void SetItemNum(int ItemNum);

	// m_snItemNumのGet関数
	static int GetItemNum();

	//  m_snItemNumを初期化する
	static void ResetItemNum();

//private:
//	void SetItem();
//public:

	///// <summary>
	///// m_pacDataInfoのポインタを取得する
	///// </summary>
	///// <returns>m_pacDataInfo</returns>
	//CArray<CDataInfo*>* Getm_pacDataInfo_h();

	///// <summary>
	///// m_pacDataInfoのポインタを
	///// </summary>
	///// <param name="pacDataInfo"></param>
	//void Setm_pacDataInfo_h(CArray<CDataInfo*>* pacDataInfo);

	//TDataInfo m_tDataInfo;

	int m_nId; // ID
	CString m_csFirstName; // 名前（性）
	CString m_csLastName; // 名前（名）
	int m_nAge; // 年齢
	ESex m_eSex; // 性別 
	int m_nHeight; // 身長
	int m_nWeight; // 体重
	CString m_csFrom; // 出身地

private:
	static CString* m_cspItem; // csvデータ項目名配列

	//CArray<CDataInfo*>* m_pacDataInfo_h; // CDataInfo*型CArrayのポインタ

private:
	// 初めに読み込んだデータの一行目のカンマ数
	static int m_snItemNum;

//private:
//	// メンバ変数にセットする。
//	void SetMember();
};
