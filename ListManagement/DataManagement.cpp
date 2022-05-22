#include "pch.h"
#include "DataManagement.h"
#define NOT_FOUND_FILE -1 // ���̓t�@�C�������݂��Ȃ��G���[
#define FILE_OPEN_FAILED -2 // �t�@�C���I�[�v���Ɏ��s
#define WRITE_SUCCESS 1; // �������ݏ�������


CArray<CDataInfo*>* m_pacDataInfo = nullptr;


CDataManagement::CDataManagement()
{

}
/// <summary>
/// �f�X�g���N�^
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
/// csv�t�@�C���̓ǂݍ��ݎ��s�֐�
/// </summary>
/// <param name="cReadPath">�ǂݍ��݃p�X</param>
/// <returns>0:�����@0�ȊO:���s</returns>
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

	// CArray<CDataInfo>�̃C���X�^���X���쐬����Ă���΁Anew���Ȃ��B
	if (m_pacDataInfo == nullptr)
	{
		m_pacDataInfo = new CArray<CDataInfo*>();
		m_pacDataInfo->RemoveAll();

	}
	
	// CDataInfo�C���X�^���X�̍쐬
	CDataInfo* cDataInfo = new CDataInfo();
	m_pacDataInfo->Add(cDataInfo);

	// ��s���e�L�X�g�ǂݍ���
	CString csReadLineText;
	while (cFile.ReadString(csReadLineText))
	{
		// �J�n�����ʒu�̏�����
		int nStart = 0;
		// 
		int nPos = -1;
		// nPos��nStart����','�܂ł̕�����
		nPos = csReadLineText.Find(',', nStart);
		// m_patDataInfoList->ElementAt(0).nId = (int)csReadLineText.Mid(nStart, nPos - nStart);
		// �B�|�@��������
		//cDataInfo->m_ptDataInfo->nId= _ttoi(csReadLineText.Mid(nStart, nPos - nStart));
		//m_patDataInfoList->ElementAt(0)->nId = _ttoi(csReadLineText.Mid(nStart, nPos - nStart));

		
	}
	cFile.Close();


	
	// �f�o�b�O�p�f�[�^
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
/// �f�[�^�̏����o�������s
/// </summary>
/// <param name="cWritePath">�����o����t�H���_�̐e�p�X</param>
/// <param name="cFileName">�����o���p�̃t�@�C����</param>
/// <param name="cDataInfo">�����o���p�f�[�^</param>
/// <returns>0�F�����@0�F�ȊO���s</returns>
int CDataManagement::WriteData(wchar_t cWritePath[MAX_PATH], wchar_t cFileName[_MAX_FNAME])
{

	CString csWritePath = CString(cWritePath) + _T("\\") + CString(cFileName);
	// �C���X�^���X�̐���
	CStdioFile cStdioFile;
	TDataInfo tDataInfo;


// **************�e�X�g�p*****************
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
		tDataInfo.csFirstName, // ���O�i���j
		tDataInfo.csLastName, // ���O�i���j
		tDataInfo.nAge, // �N��
		tDataInfo.eSex, // ���� 
		tDataInfo.nHeight, // �g��
		tDataInfo.nWeight, // �̏d
		tDataInfo.csFrom); // �o�g�n

	//********************************
	

	// �f�[�^�o�͐�t�@�C�����I�[�v��
	if (cStdioFile.Open(csWritePath, CFile::modeReadWrite | CFile::shareDenyNone | CFile::modeCreate | CFile::modeNoTruncate) == FALSE) 
	{
		//�@�t�@�C���I�[�v���Ɏ��s
		return FILE_OPEN_FAILED;
	}

	// �t�@�C���̍Ō�ɃA�^�b�`
	cStdioFile.SeekToEnd();
	
	// �ǉ����ꂽ�f�[�^�̍s���������[�v
	for(int i = 0; i < m_pacDataInfo->GetCount(); i++) 
	{
		// �������ݗp�̃f�[�^���擾
		m_pacDataInfo->ElementAt(i)->GetData(
			&tDataInfo.nId, // ID
			&tDataInfo.csFirstName, // ���O�i���j
			&tDataInfo.csLastName, // ���O�i���j
			&tDataInfo.nAge, // �N��
			&tDataInfo.eSex, // ���� 
			&tDataInfo.nHeight, // �g��
			&tDataInfo.nWeight, // �̏d
			&tDataInfo.csFrom); // �o�g�n

		// �������ݏ���
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

	
	// �t�@�C�����N���[�Y
	cStdioFile.Close();

    return WRITE_SUCCESS;
}

//******************�B�|��������***********************************
int CDataManagement::ReadFileDataKK(wchar_t cReadPath[MAX_PATH])
{
	CString csReadPath = cReadPath;
	// �C���X�^���X�̐���
	CFileFind cFileFind;
	// ���̓t�@�C�������݂��邩�m�F
	if (cFileFind.FindFile(csReadPath) == 0) // FindFile�֐��̖߂�l��0�ȊO�Ő��튮��
	{
		return NOT_FOUND_FILE;
	}
	//�C���X�^���X�̐���
	CStdioFile cStdioFile;
	// �f�[�^�o�͐�t�@�C�����I�[�v��
	if (cStdioFile.Open(csReadPath, CFile::modeReadWrite | CFile::shareDenyNone | CFile::modeCreate | CFile::modeNoTruncate) == FALSE)
	{
		//�@�t�@�C���I�[�v���Ɏ��s
		return FILE_OPEN_FAILED;
	}

	// �f�[�^���̃����o�ϐ�����������Ԃ̏ꍇnew����
	if (m_pacDataInfo == nullptr)
	{
		m_pacDataInfo = new CArray<CDataInfo*>();
		m_pacDataInfo->RemoveAll();

	}

	// CDataInfo�C���X�^���X�̍쐬
	CDataInfo* pcDataInfo;

	pcDataInfo->m_tDataInfo.nId;
	pcDataInfo->m_tDataInfo.csFirstName;
	pcDataInfo->m_tDataInfo.csLastName;
	pcDataInfo->m_tDataInfo.nAge;
	pcDataInfo->m_tDataInfo.eSex;
	pcDataInfo->m_tDataInfo.nHeight;
	pcDataInfo->m_tDataInfo.nWeight;
	pcDataInfo->m_tDataInfo.csFrom;

	// �f�[�^����ǉ�
	m_pacDataInfo->Add(pcDataInfo);

	CString csCSVData;;

	// ��s���e�L�X�g�ǂݍ���
	CString csReadLineText;
	BOOL bRet = TRUE;

	while (bRet)
	{
		bRet = cStdioFile.ReadString(csReadLineText);

		// �J�n�����ʒu�̏�����
		int nStart = 0;
		// 
		int nPos = -1;
		BOOL bCycle = TRUE;
		// nPos��nStart����','�܂ł̕�����
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



	// �f�o�b�O�p�f�[�^
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