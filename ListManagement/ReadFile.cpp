#include "pch.h"
#include "ReadFile.h"
#include "DataInfo.h"

CArray <TDataInfo*>* m_patDataInfoList = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
CReadFile::CReadFile()
{

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CReadFile::~CReadFile()
{
}

int CReadFile::ReadFileData(wchar_t cReadPath[MAX_PATH])
{
	CString csReadPath = cReadPath;
	// �C���X�^���X�̐���
	CFileFind cFileFind;
	//
	CDataInfo cDataInfo;
	// ���̓t�@�C�������݂��邩�m�F
	if (cFileFind.FindFile(csReadPath) == 0) // FindFile�֐��̖߂�l��0�ȊO�Ő��튮��
	{
		return NOT_FOUND_FILE;
	}



	CStdioFile cFile;
	cFile.Open(csReadPath, CFile::modeRead);
	// ��s���e�L�X�g�ǂݍ���
	CString csReadLineText;
	while (cFile.ReadString(csReadLineText))
	{
		// �擪�����ʒu
		int nStart = 0;
		// 
		int nPos = -1; 
		nPos = csReadLineText.Find(',', nStart);
//		m_patDataInfoList->ElementAt(0).nId = (int)csReadLineText.Mid(nStart, nPos - nStart);
	}
	cFile.Close();
	return 0;
}
