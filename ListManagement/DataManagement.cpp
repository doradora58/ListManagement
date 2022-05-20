#include "pch.h"
#include "DataManagement.h"
#define NOT_FOUND_FILE -1 // ���̓t�@�C�������݂��Ȃ��G���[


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
	// �C���X�^���X�̐���
	CFileFind cFileFind;

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
	// �C���X�^���X�̐���
	CStdioFile cStdioFile;
	// �f�[�^�o�͐�t�@�C�����I�[�v��
	cStdioFile.Open(csWritePath, CFile::modeReadWrite | CFile::shareDenyNone | CFile::modeCreate | CFile::modeNoTruncate);
	// �t�@�C���̍Ō�ɃA�^�b�`
	cStdioFile.SeekToEnd();
	// �t�@�C���Ƀf�[�^����������
	TDataInfo tDataInfo;
	
	
	m_pacDataInfo->ElementAt(0)->GetData(
		tDataInfo.csFirstName,
		);

	a;
    return 0;
}
