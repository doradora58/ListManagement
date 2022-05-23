#include "pch.h"
#include "DataManagement.h"
#define NOT_FOUND_FILE -1 // 入力ファイルが存在しないエラー
#define FILE_OPEN_FAILED -2 // ファイルが見つからないエラー
#define CSV_COLUMNS_NUM 8 // csvファイルの列数
#define WRITE_SUCCESS 0 // 書き込み処理成功
#define NO_DATA -3 // データがないためエラー


CArray<CDataInfo*>* m_pacDataInfo = nullptr;


CDataManagement::CDataManagement()
{

}

/// <summary>
/// デストラクタ
/// </summary>
CDataManagement::~CDataManagement()
{
	//if (m_pacDataInfo != nullptr)
	//{
	//	for (int i = 0; i < m_pacDataInfo->GetCount(); i++)
	//	{

	//		CDataInfo* pDataInfo = m_pacDataInfo->GetAt(i);
	//		delete pDataInfo;
	//	}
	//	m_pacDataInfo->RemoveAll();
	//	delete m_pacDataInfo;
	//	m_pacDataInfo = NULL;
	//}
}

/// <summary>
/// csvファイルの読み込み実行関数
/// </summary>
/// <param name="cReadPath">読み込みパス</param>
/// <returns>0:成功　0以外:失敗</returns>

int CDataManagement::ReadFileData(TCHAR cReadPath[MAX_PATH])
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
		// カンマの文字位置
		int nPos = -1;
		// nPosをnStartから','までの文字数
		nPos = csReadLineText.Find(',', nStart);
		// 読み込みデータの一時保存配列
		CString ReadData[CSV_COLUMNS_NUM];

		// 一行分のカンマ区切りの要素を抜き出す
		for (int i = 0; nPos > -1; i++)
		{
			ReadData[i] = csReadLineText.Mid(nStart, nPos - nStart);
			nStart = nPos + 1;
			// nPosを次のカンマ位置まで移動。カンマがない場合、nPosに-1を返す。
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
int CDataManagement::WriteData(TCHAR cWritePath[MAX_PATH], TCHAR cFileName[_MAX_FNAME])
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
		switch (tDataInfo.eSex)
		{
		case(ESex::MAN):
			cStdioFile.WriteString(_T("男\n"));
			break;
		case(ESex::WOMAN):
			cStdioFile.WriteString(_T("女\n"));
			break;
		default:
			cStdioFile.WriteString(_T("その他\n"));
			break;
		}
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
int CDataManagement::ReadFileDataKK(TCHAR cReadPath[MAX_PATH])
{
	CString csReadPath = cReadPath;
	// インスタンスの生成
	CFileFind cFileFind;
	// 入力ファイルが存在するか確認
	if (cFileFind.FindFile(csReadPath) == 0) // FindFile関数の戻り値が0以外で正常完了
	{
		return NOT_FOUND_FILE;
	}
	////インスタンスの生成
	//CFile cFile = CFile();
	//// データ出力先ファイルをオープン
	//if (cFile.Open(csReadPath, CFile::modeReadWrite | CFile::shareDenyNone | CFile::modeCreate | CFile::modeNoTruncate) == FALSE)
	//{
	//	//　ファイルオープンに失敗
	//	return FILE_OPEN_FAILED;
	//}

	//TCHAR* szCsvData = new TCHAR[cFile.GetLength()];
	//memset(szCsvData, NULL, cFile.GetLength());

	//if (cFile.Read(szCsvData, (UINT)cFile.GetLength()) <= 0) 
	//{
	//	// データ無し
	//	return NO_DATA;
	//}

	//cFile.Close();

	//// データ情報のメンバ変数が初期化状態の場合newする
	//if (m_pacDataInfo == nullptr)
	//{
	//	m_pacDataInfo = new CArray<CDataInfo*>();
	//	m_pacDataInfo->RemoveAll();

	//}

	//CString CStr = szCsvData;
	//delete[](szCsvData);

	//int crLfNum1 = 0;
	//int crLfNum2 = 0;

	//CArray<CStringArray*> CStringArrayList;
	//CStringArrayList.RemoveAll();

	//while (true) 
	//{
	//	// １行目終端
	//	crLfNum2 = CStr.Find('\n', crLfNum1 + 1);
	//	// １行分の文字列
	//	CString CStr1;

	//	if (crLfNum2 <= 0) 
	//	{
	//		CStr1 = CStr.Mid(crLfNum1, CStr.GetLength() + 1 - crLfNum1);

	//	}
	//	else
	//	{
	//		CStr1= CStr.Mid(crLfNum1, crLfNum2 + 1 - crLfNum1);
	//	}

	//	// 改行コードを削除
	//	CStr1.Replace(_T("\r\n"), _T(""));

	//	// カンマ区切りで分解用
	//	int delimiterNum1 = 0;
	//	int delimiterNum2 = 0;
	//	CStringArray* CStrArray = new CStringArray();
	//	CStrArray->RemoveAll();

	//	delimiterNum2 = CStr1.Find(',', delimiterNum1);
	//	while(delimiterNum2 != -1) 
	//	{
	//		CString CStr2;
	//		if (delimiterNum2 <= 0)
	//		{
	//			CStr2 = CStr1.Mid(delimiterNum1, CStr1.GetLength() + 1 - delimiterNum1);
	//		}
	//		else
	//		{
	//			CStr2 = CStr1.Mid(delimiterNum1,delimiterNum2 + 1 - delimiterNum1);

	//		}



	//	}
	//}





	//CArray<CString*>* csaData = new CArray<CString*>();
	//csaData->RemoveAll();

	//int iStart = 0;
	//int iPos = -1;

	//CString* restoken;
	//iPos = csLine.Find(',', iStart);

	//while (iPos > -1)
	//{
	//	restoken =&csLine.Mid(iStart, iPos - iStart);
	//	csaData->Add(restoken);


	//	iStart = iPos + 1;
	//	iPos = csLine.Find(',', iStart);

	//	if (iPos == -1)
	//	{
	//		restoken = &csLine.Mid(iStart);
	//		csaData->Add(restoken);
	//	}
	//}






	return 0;
}

int CDataManagement::WriteDataKK(TCHAR cWritePath[MAX_PATH], TCHAR cFileName[_MAX_FNAME])
{
	return 0;
}
