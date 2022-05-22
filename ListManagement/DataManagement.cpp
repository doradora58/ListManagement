#include "pch.h"
#include "DataManagement.h"
#define NOT_FOUND_FILE -1 // 入力ファイルが存在しないエラー
#define FILE_OPEN_FAILED -2 // ファイルオープンに失敗
#define WRITE_SUCCESS 1; // 書き込み処理成功


CArray<CDataInfo*>* m_pacDataInfo = nullptr;


CDataManagement::CDataManagement()
{

}
/// <summary>
/// デストラクタ
/// </summary>
CDataManagement::~CDataManagement()
{
	if (m_pacDataInfo != nullptr)
	{
		for (int i = 0; i < m_pacDataInfo->GetCount(); i++)
		{

			CDataInfo* pDataInfo = m_pacDataInfo->GetAt(i);
			delete pDataInfo;
		}
		m_pacDataInfo->RemoveAll();
		delete m_pacDataInfo;
		m_pacDataInfo = NULL;
	}
}

/// <summary>
/// csvファイルの読み込み実行関数
/// </summary>
/// <param name="cReadPath">読み込みパス</param>
/// <returns>0:成功　0以外:失敗</returns>
int CDataManagement::ReadFileData(wchar_t cReadPath[MAX_PATH])
{
	CString csReadPath = cReadPath;
	// インスタンスの生成
	CFileFind cFileFind;

	// 入力ファイルが存在するか確認
	if (cFileFind.FindFile(csReadPath) == 0) // FindFile関数の戻り値が0以外で正常完了
	{
		return NOT_FOUND_FILE;
	}



	CStdioFile cFile;
	cFile.Open(csReadPath, CFile::modeRead);

	// CArray<CDataInfo>のインスタンスが作成されていれば、newしない。
	if (m_pacDataInfo == nullptr)
	{
		m_pacDataInfo = new CArray<CDataInfo*>();
		m_pacDataInfo->RemoveAll();

	}
	
	// CDataInfoインスタンスの作成
	CDataInfo* cDataInfo = new CDataInfo();
	m_pacDataInfo->Add(cDataInfo);

	// 一行分テキスト読み込み
	CString csReadLineText;
	while (cFile.ReadString(csReadLineText))
	{
		// 開始文字位置の初期化
		int nStart = 0;
		// 
		int nPos = -1;
		// nPosをnStartから','までの文字数
		nPos = csReadLineText.Find(',', nStart);
		// m_patDataInfoList->ElementAt(0).nId = (int)csReadLineText.Mid(nStart, nPos - nStart);
		// 沓掛　試し書き
		//cDataInfo->m_ptDataInfo->nId= _ttoi(csReadLineText.Mid(nStart, nPos - nStart));
		//m_patDataInfoList->ElementAt(0)->nId = _ttoi(csReadLineText.Mid(nStart, nPos - nStart));

		
	}
	cFile.Close();


	
	// デバッグ用データ
	/*
	TDataInfo tDataInfo;
	tDataInfo.nId = 111;
	tDataInfo.csFirstName = _T("aaa");
	tDataInfo.csLastName= _T("aaa");
	tDataInfo.nAge = 2324;
	tDataInfo.eSex = ESex::MAN;
	tDataInfo.nHeight = 123;
	tDataInfo.nWeight = 344;
	tDataInfo.csFrom = _T("ooita");

	m_pacDataInfo->ElementAt(0)->SetData(
		tDataInfo.nId,
		tDataInfo.csFirstName,
		tDataInfo.csLastName,
		tDataInfo.nAge,
		tDataInfo.eSex,
		tDataInfo.nHeight,
		tDataInfo.nWeight,
		tDataInfo.csFrom);
	*/
    return 0;
}






/// <summary>
/// データの書き出しを実行
/// </summary>
/// <param name="cWritePath">書き出し先フォルダの親パス</param>
/// <param name="cFileName">書き出し用のファイル名</param>
/// <param name="cDataInfo">書き出し用データ</param>
/// <returns>0：成功　0：以外失敗</returns>
int CDataManagement::WriteData(wchar_t cWritePath[MAX_PATH], wchar_t cFileName[_MAX_FNAME])
{

	CString csWritePath = CString(cWritePath) + _T("\\") + CString(cFileName);
	// インスタンスの生成
	CStdioFile cStdioFile;
	TDataInfo tDataInfo;


// **************テスト用*****************
	tDataInfo.nId = 111;
	tDataInfo.csFirstName = _T("aaa");
	tDataInfo.csLastName = _T("avdadaafaaa");
	tDataInfo.nAge = 2324;
	tDataInfo.eSex = ESex::MAN;
	tDataInfo.nHeight = 123;
	tDataInfo.nWeight = 344;
	tDataInfo.csFrom = _T("ooita");

	m_pacDataInfo->ElementAt(0)->SetData(
		tDataInfo.nId,
		tDataInfo.csFirstName,
		tDataInfo.csLastName,
		tDataInfo.nAge,
		tDataInfo.eSex,
		tDataInfo.nHeight,
		tDataInfo.nWeight,
		tDataInfo.csFrom);

	m_pacDataInfo->ElementAt(1)->SetData(
		tDataInfo.nId,
		tDataInfo.csFirstName,
		tDataInfo.csLastName,
		tDataInfo.nAge,
		tDataInfo.eSex,
		tDataInfo.nHeight,
		tDataInfo.nWeight,
		tDataInfo.csFrom);

	m_pacDataInfo->ElementAt(2)->SetData(
		tDataInfo.nId, // ID
		tDataInfo.csFirstName, // 名前（性）
		tDataInfo.csLastName, // 名前（名）
		tDataInfo.nAge, // 年齢
		tDataInfo.eSex, // 性別 
		tDataInfo.nHeight, // 身長
		tDataInfo.nWeight, // 体重
		tDataInfo.csFrom); // 出身地

	//********************************
	

	// データ出力先ファイルをオープン
	if (cStdioFile.Open(csWritePath, CFile::modeReadWrite | CFile::shareDenyNone | CFile::modeCreate | CFile::modeNoTruncate) == FALSE) 
	{
		//　ファイルオープンに失敗
		return FILE_OPEN_FAILED;
	}

	// ファイルの最後にアタッチ
	cStdioFile.SeekToEnd();
	
	// 追加されたデータの行数だけループ
	for(int i = 0; i < m_pacDataInfo->GetCount(); i++) 
	{
		// 書き込み用のデータを取得
		m_pacDataInfo->ElementAt(i)->GetData(
			&tDataInfo.nId, // ID
			&tDataInfo.csFirstName, // 名前（性）
			&tDataInfo.csLastName, // 名前（名）
			&tDataInfo.nAge, // 年齢
			&tDataInfo.eSex, // 性別 
			&tDataInfo.nHeight, // 身長
			&tDataInfo.nWeight, // 体重
			&tDataInfo.csFrom); // 出身地

		// 書き込み処理
		CString csId;
		csId.Format(_T("%d\n"), tDataInfo.nId);
		cStdioFile.WriteString(csId);
		cStdioFile.WriteString(tDataInfo.csFirstName + _T("\n"));
		cStdioFile.WriteString(tDataInfo.csLastName + _T("\n"));
		CString csAge;
		csAge.Format(_T("%d\n"), tDataInfo.nAge);
		cStdioFile.WriteString(csAge);
		CString csSex;
		csSex.Format(_T("%d\n"), tDataInfo.eSex);
		cStdioFile.WriteString(csSex);
		CString csHeight;
		csHeight.Format(_T("%d\n"), tDataInfo.nHeight);
		cStdioFile.WriteString(csHeight);
		CString csWeight;
		csWeight.Format(_T("%d\n"), tDataInfo.nWeight);
		cStdioFile.WriteString(csWeight);
		cStdioFile.WriteString(tDataInfo.csFrom + _T("\n"));

	}

	
	// ファイルをクローズ
	cStdioFile.Close();

    return WRITE_SUCCESS;
}

//******************沓掛試し書き***********************************
int CDataManagement::ReadFileDataKK(wchar_t cReadPath[MAX_PATH])
{
	CString csReadPath = cReadPath;
	// インスタンスの生成
	CFileFind cFileFind;
	// 入力ファイルが存在するか確認
	if (cFileFind.FindFile(csReadPath) == 0) // FindFile関数の戻り値が0以外で正常完了
	{
		return NOT_FOUND_FILE;
	}
	//インスタンスの生成
	CStdioFile cStdioFile;
	// データ出力先ファイルをオープン
	if (cStdioFile.Open(csReadPath, CFile::modeReadWrite | CFile::shareDenyNone | CFile::modeCreate | CFile::modeNoTruncate) == FALSE)
	{
		//　ファイルオープンに失敗
		return FILE_OPEN_FAILED;
	}

	// データ情報のメンバ変数が初期化状態の場合newする
	if (m_pacDataInfo == nullptr)
	{
		m_pacDataInfo = new CArray<CDataInfo*>();
		m_pacDataInfo->RemoveAll();

	}

	// CDataInfoインスタンスの作成
	CDataInfo* pcDataInfo;

	pcDataInfo->m_tDataInfo.nId;
	pcDataInfo->m_tDataInfo.csFirstName;
	pcDataInfo->m_tDataInfo.csLastName;
	pcDataInfo->m_tDataInfo.nAge;
	pcDataInfo->m_tDataInfo.eSex;
	pcDataInfo->m_tDataInfo.nHeight;
	pcDataInfo->m_tDataInfo.nWeight;
	pcDataInfo->m_tDataInfo.csFrom;

	// データ情報を追加
	m_pacDataInfo->Add(pcDataInfo);

	CString csCSVData;;

	// 一行分テキスト読み込み
	CString csReadLineText;
	BOOL bRet = TRUE;

	while (bRet)
	{
		bRet = cStdioFile.ReadString(csReadLineText);

		// 開始文字位置の初期化
		int nStart = 0;
		// 
		int nPos = -1;
		BOOL bCycle = TRUE;
		// nPosをnStartから','までの文字数
		while (bCycle) 
		{
			nPos = csReadLineText.Find(',', nStart);
			csCSVData += csReadLineText.Mid(nStart, nPos - nStart);
			nStart = nPos + 1;
			if (nPos == -1)
			{
				bCycle = FALSE;

			}
		}

	
	}
	cStdioFile.Close();



	// デバッグ用データ
	/*
	TDataInfo tDataInfo;
	tDataInfo.nId = 111;
	tDataInfo.csFirstName = _T("aaa");
	tDataInfo.csLastName= _T("aaa");
	tDataInfo.nAge = 2324;
	tDataInfo.eSex = ESex::MAN;
	tDataInfo.nHeight = 123;
	tDataInfo.nWeight = 344;
	tDataInfo.csFrom = _T("ooita");

	m_pacDataInfo->ElementAt(0)->SetData(
		tDataInfo.nId,
		tDataInfo.csFirstName,
		tDataInfo.csLastName,
		tDataInfo.nAge,
		tDataInfo.eSex,
		tDataInfo.nHeight,
		tDataInfo.nWeight,
		tDataInfo.csFrom);
	*/

	return 0;
}

int CDataManagement::WriteDataKK(wchar_t cWritePath[MAX_PATH], wchar_t cFileName[_MAX_FNAME])
{
	return 0;
}
//*********************************************************