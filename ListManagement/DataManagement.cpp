#include "pch.h"
#include "DataManagement.h"
#define NOT_FOUND_FILE -1 // ���̓t�@�C�������݂��Ȃ��G���[
#define CSV_COLUMNS_NUM 8 // csv�t�@�C���̗�


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

	// CArray<CDataInfo>�̃C���X�^���X���쐬����Ă���΁Anew���Ȃ��B
	if (m_pacDataInfo == nullptr)
	{
		m_pacDataInfo = new CArray<CDataInfo*>();
		m_pacDataInfo->RemoveAll();

	}
	
	// ��s���e�L�X�g�ǂݍ���
	CString csReadLineText;

	
	for (int I = 0; cFile.ReadString(csReadLineText); I++)
	{
		// CDataInfo�C���X�^���X�̍쐬
		CDataInfo* cDataInfo = new CDataInfo();
		m_pacDataInfo->Add(cDataInfo);
		// �J�n�����ʒu�̏�����
		int nStart = 0;
		// 
		int nPos = -1;
		// nPos��nStart����','�܂ł̕�����
		nPos = csReadLineText.Find(',', nStart);

		CString ReadData[CSV_COLUMNS_NUM];

		// ��s���̃J���}��؂�̗v�f�𔲂��o��
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
		// �B�|�@��������
		//cDataInfo->m_ptDataInfo->nId= _ttoi(csReadLineText.Mid(nStart, nPos - nStart));
		//m_patDataInfoList->ElementAt(0)->nId = _ttoi(csReadLineText.Mid(nStart, nPos - nStart));	
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
