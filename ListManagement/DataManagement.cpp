#include "pch.h"
#include "DataManagement.h"
#define NOT_FOUND_FILE -1 // 入力ファイルが存在しないエラー


CArray<CDataInfo*>* m_patDataInfo = nullptr;


CDataManagement::CDataManagement()
{
	if (m_patDataInfo != nullptr) 
	{
		return;
	}
		m_patDataInfo = nullptr;
}

CDataManagement::~CDataManagement()
{
}

int CDataManagement::ReadFileData(wchar_t cReadPath[MAX_PATH])
{
	CString csReadPath = cReadPath;
	// インスタンスの生成
	CFileFind cFileFind;

	if (m_patDataInfo == nullptr) 
	{
		m_patDataInfo = new CArray<CDataInfo*>();
		m_patDataInfo->RemoveAll();

	}
	CDataInfo* cDataInfo = new CDataInfo();
	m_patDataInfo->Add(cDataInfo);



	// 入力ファイルが存在するか確認
	if (cFileFind.FindFile(csReadPath) == 0) // FindFile関数の戻り値が0以外で正常完了
	{
		return NOT_FOUND_FILE;
	}



	CStdioFile cFile;
	cFile.Open(csReadPath, CFile::modeRead);
	// 一行分テキスト読み込み
	CString csReadLineText;
	while (cFile.ReadString(csReadLineText))
	{
		// 先頭文字位置
		int nStart = 0;
		// 
		int nPos = -1;
		nPos = csReadLineText.Find(',', nStart);
		// m_patDataInfoList->ElementAt(0).nId = (int)csReadLineText.Mid(nStart, nPos - nStart);
		// 沓掛　試し書き
		//cDataInfo->m_ptDataInfo->nId= _ttoi(csReadLineText.Mid(nStart, nPos - nStart));
		//m_patDataInfoList->ElementAt(0)->nId = _ttoi(csReadLineText.Mid(nStart, nPos - nStart));
		
		
	}
	cFile.Close();
    return 0;
}

int CDataManagement::WriteData(wchar_t cWritePath[MAX_PATH], wchar_t cFileName[_MAX_FNAME], TDataInfo tDataInfo)
{
	CString csWritePath = CString(cWritePath) + _T("\\") + CString(cFileName);
	// インスタンスの生成
	CStdioFile cStdioFile;
	// データ出力先ファイルをオープン
	cStdioFile.Open(csWritePath, CFile::modeReadWrite | CFile::shareDenyNone | CFile::modeCreate | CFile::modeNoTruncate);
	// ファイルの最後にアタッチ
	cStdioFile.SeekToEnd();
	// ファイルにデータを書き込む
	CString csId;
	csId.Format(_T("%s"), tDataInfo.nId + ",");
	cStdioFile.WriteString(csId);
	cStdioFile.WriteString((CString)tDataInfo.csFirstName + _T(","));
	cStdioFile.WriteString(tDataInfo.csLastName + _T(","));
	CString csAge;
	csAge.Format(_T("%d"), tDataInfo.nAge + _T(","));
	cStdioFile.WriteString(csAge + _T(","));
	CString csSex;
	csSex.Format(_T("%d"), tDataInfo.eSex + _T(","));
	cStdioFile.WriteString(csSex + _T(","));
	CString csHeight;
	csSex.Format(_T("%d"), tDataInfo.nHeight + _T(","));
	cStdioFile.WriteString(csHeight);
	CString csWeight;
	csWeight.Format(_T("%d"), tDataInfo.nWeight + _T(","));
	cStdioFile.WriteString(csWeight + _T(","));
	cStdioFile.WriteString(tDataInfo.csFrom + _T(","));


    return 0;
}
