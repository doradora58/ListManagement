#include "pch.h"
#include "DataManagement.h"
#include "Library.h"

// メンバ変数のデータ情報
CArray<CDataInfo*>* m_pacDataInfo = nullptr;


CDataManagement::CDataManagement()
{
	m_nCount = 0;
}

/// <summary>
/// デストラクタ
/// </summary>
CDataManagement::~CDataManagement()
{

}

/// <summary>
/// csvファイルの読み込み実行関数
/// </summary>
/// <param name="cReadPath">読み込みパス</param>
/// <returns>0:成功　0以外:失敗</returns>
int CDataManagement::ReadFileData(TCHAR cReadPath[MAX_PATH])
{
	try
	{
		// 行数
		int nRowNum = 0;

		// 画面に入力されたパスをCStringに変換
		CString csReadPath = cReadPath;
		// インスタンスの生成
		CFileFind cFileFind;

		// 入力ファイルが存在するか確認
		if (cFileFind.FindFile(csReadPath) == 0) // FindFile関数の戻り値が0以外で正常完了
		{
			throw NOT_FOUND_FILE;
		}

		CStdioFile cFile;
		// Readモードでファイルオープン
		cFile.Open(csReadPath, CFile::modeRead | CFile::typeBinary);

		// 一行分テキスト読み込みCArray
		CArray<CString> CSReadLineTexArray;

		// 一行文のテキスト格納buffer
		CString csReadLineText;

		// 
		CArray<CStringArray*> CStringArrayList;
		CStringArrayList.RemoveAll();

		// 読み取りデータを行毎に分解し、格納
		for (int i = 0; cFile.ReadString(csReadLineText); i++)
		{
			CSReadLineTexArray.Add(csReadLineText);

			// 行数のカウント
			nRowNum++;
		}

		cFile.Close();

		// 各行に含まれるカンマ数が一行目のカンマ数と同じかcheckする
		for (int i = 0; i < nRowNum; i++)
		{
			int nCommaCount = this->CountCommaOcuurence(CSReadLineTexArray.ElementAt(i));
			// 一行目の場合、カンマ数をCDataInfoクラスの静的メンバ変数に保存する。
			if (i == 0)
			{
				CDataInfo::SetItemNum(nCommaCount);
			}
			// i行目のカンマ数がm_snItemNumと等しいか比較
			if (CDataInfo::GetItemNum() != nCommaCount)
			{
				throw CSV_FORMAT_ERROR;
			}
		}

		// CArray<CDataInfo>のインスタンスが作成されていれば、newしない。
		if (m_pacDataInfo == nullptr)
		{
			m_pacDataInfo = new CArray<CDataInfo*>();
			m_pacDataInfo->RemoveAll();


		}

		for (int I = 0; I < nRowNum; I++)
		{
			// CDataInfoインスタンスの作成
			CDataInfo* cDataInfo = new CDataInfo();
			m_pacDataInfo->Add(cDataInfo);

			// 一行分の要素格納array
			CStringArray* CStrArray = new CStringArray();
			CStrArray->RemoveAll();

			// 開始文字位置の初期化
			int nStart = 0;
			// カンマの文字位置
			int nPos = -1;

			// nPosをnStartから','までの文字数
			nPos = CSReadLineTexArray.ElementAt(I).Find(',', nStart);

			// 一行分のカンマ区切りの要素を抜き出す
			for (int i = 0; nPos > -1; i++)
			{
				// 要素収納buffer
				CString ReadData = "";

				// nStartからnPos-nStart文字分切り出す
				ReadData = CSReadLineTexArray.ElementAt(I).Mid(nStart, nPos - nStart);

				// 開始文字位置をカンマの次に
				nStart = nPos + 1;

				// nPosを次のカンマ位置まで移動。カンマがない場合、nPosに-1を返す。
				nPos = CSReadLineTexArray.ElementAt(I).Find(',', nStart);

				CStrArray->Add(ReadData);

				// 最終要素
				if (nPos == -1)
				{
					ReadData = CSReadLineTexArray.ElementAt(I).Mid(nStart);
					CStrArray->Add(ReadData);

					CStringArrayList.Add(CStrArray);

					cDataInfo->SetData(CStringArrayList.ElementAt(I));

					CStringArrayList.ElementAt(I)->RemoveAll();
					delete CStringArrayList.ElementAt(I);

				}
			}
		}
		return SUCCESS;
	}
	catch (int i)
	{
		return i;
	}
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

	if (m_pacDataInfo == nullptr)
	{
		return NO_DATAINFO;
	}


	// 追加されたデータの行数だけループ
	for (int i = 0; i < m_pacDataInfo->GetCount(); i++)
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

	return SUCCESS;
}

void CDataManagement::GetDataInfo(CArray<CDataInfo*>& pacDataInfo)
{
	pacDataInfo.Copy(*m_pacDataInfo);

}

CString CDataManagement::Getm_csFileName()
{
	return m_csFileName;
}

CString CDataManagement::Getm_csReadPath()
{
	return m_csReadPath;
}




//******************沓掛試し書き***********************************
int CDataManagement::ReadFileDataKK(TCHAR cReadPath[MAX_PATH])
{
	int nRet = SUCCESS;
	CString csLogText;
	CString csReadPath = cReadPath;
	// インスタンスの生成
	CFileFind cFileFind;
	// 入力ファイルが存在するか確認
	if (cFileFind.FindFile(csReadPath) == 0) // FindFile関数の戻り値が0以外で正常完了
	{
		//　入力ファイルが存在しない
		nRet= NOT_FOUND_FILE;
		csLogText.Format(_T("Result=%d"), nRet);
		LOG(csLogText.GetBuffer(), _T(__FILE__), __LINE__, _T(__FUNCTION__))
		return nRet;
	}
	//インスタンスの生成
	CStdioFile cFile;
	// データ出力先ファイルをオープン
	if (cFile.Open(csReadPath, CFile::modeReadWrite | CFile::shareDenyNone | CFile::modeCreate | CFile::modeNoTruncate | CFile::typeBinary) == FALSE)
	{
		//　ファイルオープンに失敗
		nRet = FILE_OPEN_FAILED;
		csLogText.Format(_T("Result=%d"), nRet);
		LOG(csLogText.GetBuffer(), _T(__FILE__), __LINE__, _T(__FUNCTION__))
		return nRet;
	}

	// オブジェクトの生成
	TCHAR* szCsvData = new TCHAR[cFile.GetLength() + 1];
	memset(szCsvData, NULL, cFile.GetLength() + 1);
	
	if (cFile.Read(szCsvData, (UINT)cFile.GetLength()) <= 0)
	{
		// CSVのデータ無し
		nRet = NO_CSV_DATA;
		csLogText.Format(_T("Result=%d"), nRet);
		LOG(csLogText.GetBuffer(), _T(__FILE__), __LINE__, _T(__FUNCTION__))
		return nRet;
	}

	cFile.Close();

	// データ情報のメンバ変数が初期化状態の場合newする
	if (m_pacDataInfo == nullptr)
	{
		m_pacDataInfo = new CArray<CDataInfo*>();
		m_pacDataInfo->RemoveAll();
	}

	CString CStr = szCsvData;
	// オブジェクトの開放
	delete[](szCsvData);

	int crLfNum1 = 0;
	int crLfNum2 = 0;

	// インスタンスの生成
	CArray<CStringArray*> CStringArrayList;
	CStringArrayList.RemoveAll();

	while (true)
	{
		// オブジェクトの生成
		CStringArray* CStrArray = new CStringArray();
		CStrArray->RemoveAll();
		// １行目終端
		crLfNum2 = CStr.Find('\n', crLfNum1 + 1);
		// １行分の文字列
		CString CStr1;

		if (crLfNum2 <= 0)
		{
			CStr1 = CStr.Mid(crLfNum1, CStr.GetLength() + 1 - crLfNum1);
		}
		else
		{
			CStr1 = CStr.Mid(crLfNum1, crLfNum2 + 1 - crLfNum1);
		}
		int a;
		a = CStr1.GetLength();
		// 改行コードを削除
		CStr1.Replace(_T("\r\n"), _T(""));

		// csvファイルフォーマット比較処理
		int nCommaCount = this->CountCommaOcuurence(CStr1);
		CDataInfo::SetItemNum(nCommaCount);
		if (CDataInfo::GetItemNum() != nCommaCount)
		{
			return CSV_FORMAT_ERROR;
		}

		// カンマ区切りで分解用
		int delimiterNum1 = 0;
		int delimiterNum2 = 0;

		while (true)
		{
			//CStr1.Replace("\n", "");
			delimiterNum2 = CStr1.Find(',', delimiterNum1 + 1);

			CString CStr2 = "";
			if (delimiterNum2 <= 0)
			{
				CStr2 = CStr1.Mid(delimiterNum1, CStr1.GetLength() - delimiterNum2);
			}
			else
			{
				CStr2 = CStr1.Mid(delimiterNum1, delimiterNum2 + 1 - delimiterNum1);
			}
			CStr2.Replace(_T(","), _T(""));
			CStrArray->Add(CStr2);
			m_nCount += 1;
			

			if (delimiterNum2 <= 0)
			{
				break;
			}
			// 次のフィールドを取得できるようにする
			delimiterNum1 = delimiterNum2;
		}

		if (CStrArray->GetCount() > 1)
		{
			int a = CStrArray->GetCount();
			CStringArrayList.Add(CStrArray);

		}
		// CRLFがあるか確認
		if (crLfNum2 <= 0)
		{
			break;
		}
		// 次の行を取得できるようにする
		crLfNum1 = crLfNum2 + 1;
	}

	// 読み込んだCSVを行数でループ
	for (int i = 0; i < CStringArrayList.GetCount(); i++)
	{
		// CDataInfoオブジェクトの生成
		CDataInfo* cDataInfo = new CDataInfo();
		m_pacDataInfo->Add(cDataInfo);

		cDataInfo->SetData(CStringArrayList.ElementAt(i));

		// CStringArrayの要素オブジェクトを破棄
		CStringArray* pCStringArray = CStringArrayList.GetAt(i);
		pCStringArray->RemoveAll();
		delete pCStringArray;
	}

	CStringArrayList.RemoveAll();
	csLogText.Format(_T("Result=%d"), nRet);
	LOG(csLogText.GetBuffer(), _T(__FILE__), __LINE__, _T(__FUNCTION__))
	return nRet;
}

int CDataManagement::WriteDataKK(TCHAR cWritePath[MAX_PATH], TCHAR cFileName[_MAX_FNAME])
{
	return SUCCESS;
}


int CDataManagement::CountCommaOcuurence(CString& cstr) const
{
	int nCommaOcuurence = 0;
	int ncstrLen = cstr.GetLength();

	for (int i = 0; i < ncstrLen; i++)
	{
		char ch = cstr[i]; // デバッグ用
		if (cstr[i] == ',')
			nCommaOcuurence++;
	}

	return nCommaOcuurence;
}
