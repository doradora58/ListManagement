#include "pch.h"
#include "DataManagement.h"
#define NOT_FOUND_FILE -1 // ���̓t�@�C�������݂��Ȃ��G���[


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
	// �C���X�^���X�̐���
	CFileFind cFileFind;

	if (m_patDataInfo == nullptr) 
	{
		m_patDataInfo = new CArray<CDataInfo*>();
		m_patDataInfo->RemoveAll();

	}
	CDataInfo* cDataInfo = new CDataInfo();
	m_patDataInfo->Add(cDataInfo);



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
		// m_patDataInfoList->ElementAt(0).nId = (int)csReadLineText.Mid(nStart, nPos - nStart);
		// �B�|�@��������
		//cDataInfo->m_ptDataInfo->nId= _ttoi(csReadLineText.Mid(nStart, nPos - nStart));
		//m_patDataInfoList->ElementAt(0)->nId = _ttoi(csReadLineText.Mid(nStart, nPos - nStart));
		
		
	}
	cFile.Close();
    return 0;
}

int CDataManagement::WriteData(wchar_t cWritePath[MAX_PATH], wchar_t cFileName[_MAX_FNAME], TDataInfo tDataInfo)
{
	CString csWritePath = CString(cWritePath) + _T("\\") + CString(cFileName);
	// �C���X�^���X�̐���
	CStdioFile cStdioFile;
	// �f�[�^�o�͐�t�@�C�����I�[�v��
	cStdioFile.Open(csWritePath, CFile::modeReadWrite | CFile::shareDenyNone | CFile::modeCreate | CFile::modeNoTruncate);
	// �t�@�C���̍Ō�ɃA�^�b�`
	cStdioFile.SeekToEnd();
	// �t�@�C���Ƀf�[�^����������
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
