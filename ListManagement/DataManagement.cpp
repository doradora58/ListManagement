#include "pch.h"
#include "DataManagement.h"
#define NOT_FOUND_FILE -1 // 入力ファイルが存在しないエラー


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



	if (m_pacDataInfo == nullptr)
	{
		m_pacDataInfo = new CArray<CDataInfo*>();
		m_pacDataInfo->RemoveAll();

	}
	CDataInfo* cDataInfo = new CDataInfo();
	m_pacDataInfo->Add(cDataInfo);
	m_pacDataInfo->ElementAt(0)->SetData(_T("aaa"));
    return 0;
}

int CDataManagement::WriteData(wchar_t cWritePath[MAX_PATH], wchar_t cFileName[_MAX_FNAME])
{
	CString csWritePath = CString(cWritePath) + _T("\\") + CString(cFileName);
	// インスタンスの生成
	CStdioFile cStdioFile;
	// データ出力先ファイルをオープン
	cStdioFile.Open(csWritePath, CFile::modeReadWrite | CFile::shareDenyNone | CFile::modeCreate | CFile::modeNoTruncate);
	// ファイルの最後にアタッチ
	cStdioFile.SeekToEnd();
	// ファイルにデータを書き込む
	TDataInfo tDataInfo;
	
	
	m_pacDataInfo->ElementAt(0)->GetData(
		tDataInfo.csFirstName,
		);

	a;
    return 0;
}
