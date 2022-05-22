#include "pch.h"
#include "DataManagement.h"
#define NOT_FOUND_FILE -1 // 入力ファイルが存在しないエラー
#define CSV_COLUMNS_NUM 8 // csvファイルの列数


CArray<CDataInfo*>* m_pacDataInfo = nullptr;


CDataManagement::CDataManagement()
{

}

CDataManagement::~CDataManagement()
{
}

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
	
	// 一行分テキスト読み込み
	CString csReadLineText;

	
	for (int I = 0; cFile.ReadString(csReadLineText); I++)
	{
		// CDataInfoインスタンスの作成
		CDataInfo* cDataInfo = new CDataInfo();
		m_pacDataInfo->Add(cDataInfo);
		// 開始文字位置の初期化
		int nStart = 0;
		// 
		int nPos = -1;
		// nPosをnStartから','までの文字数
		nPos = csReadLineText.Find(',', nStart);

		CString ReadData[CSV_COLUMNS_NUM];

		// 一行分のカンマ区切りの要素を抜き出す
		for (int i = 0; nPos > -1; i++)
		{
			ReadData[i] = csReadLineText.Mid(nStart, nPos - nStart);
			nStart = nPos + 1;
			nPos = csReadLineText.Find(',', nStart);
			if (nPos == -1)
			{
				i++;
				ReadData[i] = csReadLineText.Mid(nStart);
				m_pacDataInfo->ElementAt(I)->SetData(
					ReadData[0],
					ReadData[1],
					ReadData[2],
					ReadData[3],
					ReadData[4],
					ReadData[5],
					ReadData[6],
					ReadData[7]);
				m_pacDataInfo->ElementAt(I)->m_tDataInfo.csFirstName = ReadData[0];
			}
		}
	}
		// m_patDataInfoList->ElementAt(0).nId = (int)csReadLineText.Mid(nStart, nPos - nStart);
		// 沓掛　試し書き
		//cDataInfo->m_ptDataInfo->nId= _ttoi(csReadLineText.Mid(nStart, nPos - nStart));
		//m_patDataInfoList->ElementAt(0)->nId = _ttoi(csReadLineText.Mid(nStart, nPos - nStart));	
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

	CString csLine;
	cStdioFile.ReadString(csLine);


	CArray<CString*>* csaData = new CArray<CString*>();
	csaData->RemoveAll();

	int iStart = 0;
	int iPos = -1;

	CString* restoken;
	iPos = csLine.Find(',', iStart);

	while (iPos > -1)
	{
		restoken =&csLine.Mid(iStart, iPos - iStart);
		csaData->Add(restoken);


		iStart = iPos + 1;
		iPos = csLine.Find(',', iStart);

		if (iPos == -1)
		{
			restoken = &csLine.Mid(iStart);
			csaData->Add(restoken);
		}
	}



	cStdioFile.Close();




	return 0;
}

int CDataManagement::WriteDataKK(wchar_t cWritePath[MAX_PATH], wchar_t cFileName[_MAX_FNAME])
{
	return 0;
}
