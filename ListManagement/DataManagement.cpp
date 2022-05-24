#include "pch.h"
#include "DataManagement.h"



CArray<CDataInfo*>* m_pacDataInfo = nullptr;


CDataManagement::CDataManagement()
{

}

/// <summary>
/// �f�X�g���N�^
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
/// csv�t�@�C���̓ǂݍ��ݎ��s�֐�
/// </summary>
/// <param name="cReadPath">�ǂݍ��݃p�X</param>
/// <returns>0:�����@0�ȊO:���s</returns>

int CDataManagement::ReadFileData(TCHAR cReadPath[MAX_PATH])
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
		// �J���}�̕����ʒu
		int nPos = -1;
		// nPos��nStart����','�܂ł̕�����
		nPos = csReadLineText.Find(',', nStart);
		// �ǂݍ��݃f�[�^�̈ꎞ�ۑ��z��
		CString ReadData[CSV_COLUMNS_NUM];

		// ��s���̃J���}��؂�̗v�f�𔲂��o��
		for (int i = 0; nPos > -1; i++)
		{
			ReadData[i] = csReadLineText.Mid(nStart, nPos - nStart);
			nStart = nPos + 1;
			// nPos�����̃J���}�ʒu�܂ňړ��B�J���}���Ȃ��ꍇ�AnPos��-1��Ԃ��B
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
int CDataManagement::WriteData(TCHAR cWritePath[MAX_PATH], TCHAR cFileName[_MAX_FNAME])
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
		switch (tDataInfo.eSex)
		{
		case(ESex::MAN):
			cStdioFile.WriteString(_T("�j\n"));
			break;
		case(ESex::WOMAN):
			cStdioFile.WriteString(_T("��\n"));
			break;
		default:
			cStdioFile.WriteString(_T("���̑�\n"));
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

	
	// �t�@�C�����N���[�Y
	cStdioFile.Close();

    return WRITE_SUCCESS;
}

//******************�B�|��������***********************************
int CDataManagement::ReadFileDataKK(TCHAR cReadPath[MAX_PATH])
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
	CFile cFile;
	// �f�[�^�o�͐�t�@�C�����I�[�v��
	if (cFile.Open(csReadPath, CFile::modeReadWrite | CFile::shareDenyNone | CFile::modeCreate | CFile::modeNoTruncate) == FALSE)
	{
		//�@�t�@�C���I�[�v���Ɏ��s
		return FILE_OPEN_FAILED;
	}

	TCHAR* szCsvData = new TCHAR[cFile.GetLength()];
	memset(szCsvData, NULL, cFile.GetLength());

	if (cFile.Read(szCsvData, (UINT)cFile.GetLength()) <= 0) 
	{
		// �f�[�^����
		return NO_DATA;
	}

	cFile.Close();

	// �f�[�^���̃����o�ϐ�����������Ԃ̏ꍇnew����
	if (m_pacDataInfo == nullptr)
	{
		m_pacDataInfo = new CArray<CDataInfo*>();
		m_pacDataInfo->RemoveAll();
	}

	CString CStr = szCsvData;
	delete[](szCsvData);
	int crLfNum1 = 0;
	int crLfNum2 = 0;

	CArray<CStringArray*> CStringArrayList;
	CStringArrayList.RemoveAll();

	while (true) 
	{
		CStringArray* CStrArray = new CStringArray();
		CStrArray->RemoveAll();
		// �P�s�ڏI�[
		crLfNum2 = CStr.Find('\n', crLfNum1 + 1);
		// �P�s���̕�����
		CString CStr1;

		if (crLfNum2 <= 0) 
		{
			CStr1 = CStr.Mid(crLfNum1, CStr.GetLength() + 1 - crLfNum1);
		}
		else
		{
			CStr1= CStr.Mid(crLfNum1, crLfNum2 + 1 - crLfNum1);
		}

		// ���s�R�[�h���폜
		CStr1.Replace(_T("\r\n"), _T(""));

		// �J���}��؂�ŕ���p
		int delimiterNum1 = 0;
		int delimiterNum2 = 0;
		
		while(true)
		{
			//CStr1.Replace("\n", "");
			delimiterNum2 = CStr1.Find(',', delimiterNum1 + 1);

			CString CStr2 = "";
			if (delimiterNum2 <= 0)
			{
				CStr2 = CStr1.Mid(delimiterNum1, CStr1.GetLength()  - delimiterNum2);
			}
			else
			{
				CStr2 = CStr1.Mid(delimiterNum1, delimiterNum2 + 1 - delimiterNum1);
			}
			CStr2.Replace(_T(","), _T(""));
			CStrArray->Add(CStr2);
			if (delimiterNum2 <= 0)
			{
				break;
			}
			// ���̃t�B�[���h���擾�ł���悤�ɂ���
			delimiterNum1 = delimiterNum2;
		}

		if (CStrArray->GetCount() > 1)
		{
			int a = CStrArray->GetCount();
			CStringArrayList.Add(CStrArray);
		}
		// CRLF�����邩�m�F
		if (crLfNum2 <= 0)
		{
			break;
		}
		// ���̍s���擾�ł���悤�ɂ���
		crLfNum1 = crLfNum2 + 1;
	}

	// �ǂݍ���CSV���s���Ń��[�v
	for (int i = 0; i < CStringArrayList.GetCount(); i++)
	{
		int a = CStringArrayList.GetCount();

		// CDataInfo�C���X�^���X�̍쐬
		CDataInfo* cDataInfo = new CDataInfo();
		m_pacDataInfo->Add(cDataInfo);
		for (int j = 0; j < CStringArrayList.ElementAt(i)->GetCount(); j++)
		{
			int b = CStringArrayList.ElementAt(i)->GetCount();
			switch (j)
			{
			case 0: // ID
				if (CString CStr = CStringArrayList.ElementAt(i)->ElementAt(j))
				{
					cDataInfo->m_nId = _ttoi(CStringArrayList.ElementAt(i)->ElementAt(j));
				}
				break;
			case 1: // FirstName
				if (CString CStr = CStringArrayList.ElementAt(i)->ElementAt(j))
				{
					cDataInfo->m_csFirstName = CStr;
				}
				break;
			case 2: // LastName
				if (CString CStr = CStringArrayList.ElementAt(i)->ElementAt(j))
				{
					cDataInfo->m_csLastName = CStr;
				}
				break;
			case 3: // Age
				if (CString CStr = CStringArrayList.ElementAt(i)->ElementAt(j))
				{
					cDataInfo->m_nAge = _ttoi(CStr);
				}
				break;
			case 4: // Sex
				if (CString CStr = CStringArrayList.ElementAt(i)->ElementAt(j))
				{

					if (CStr.Compare(_T("�j")))
					{
						cDataInfo->m_eSex = ESex::MAN;
					}
					else if (CStr.Compare(_T("��")))
					{
						cDataInfo->m_eSex = ESex::WOMAN;
					}
					else
					{
						cDataInfo->m_eSex = ESex::OTHER;
					}
				}
				break;
			case 5: // Height
				if (CString CStr = CStringArrayList.ElementAt(i)->ElementAt(j))
				{
					cDataInfo->m_nHeight = _ttoi(CStr);
				}
				break;
			case 6: // Weight
				if (CString CStr = CStringArrayList.ElementAt(i)->ElementAt(j))
				{
					cDataInfo->m_nWeight = _ttoi(CStr);
				}
				break;
			case 7: // From
				if (CString CStr = CStringArrayList.ElementAt(i)->ElementAt(j))
				{
					cDataInfo->m_csFrom = CStr;
				}
				break;
			default:
				break;
			}
		}
		//delete CStringArrayList.ElementAt(i);
	}
	CStringArrayList.RemoveAll();

	return 0;
}

int CDataManagement::WriteDataKK(TCHAR cWritePath[MAX_PATH], TCHAR cFileName[_MAX_FNAME])
{
	return 0;
}
