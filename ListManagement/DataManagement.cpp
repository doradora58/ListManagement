#include "pch.h"
#include "DataManagement.h"

// �����o�ϐ��̃f�[�^���
CArray<CDataInfo*>* m_pacDataInfo = nullptr;


CDataManagement::CDataManagement()
{

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CDataManagement::~CDataManagement()
{

}

///// <summary>
///// csv�t�@�C���̓ǂݍ��ݎ��s�֐�
///// </summary>
///// <param name="cReadPath">�ǂݍ��݃p�X</param>
///// <returns>0:�����@0�ȊO:���s</returns>
//int CDataManagement::ReadFileData(TCHAR cReadPath[MAX_PATH])
//{
//
//	// CArray<CDataInfo>�̃C���X�^���X���쐬����Ă���΁Anew���Ȃ��B
//	if (m_pacDataInfo == nullptr)
//	{
//		m_pacDataInfo = new CArray<CDataInfo*>();
//		m_pacDataInfo->RemoveAll();
//	}
//
//	// 
//	CString csReadPath = cReadPath;
//	// �C���X�^���X�̐���
//	CFileFind cFileFind;
//
//	// ���̓t�@�C�������݂��邩�m�F
//	if (cFileFind.FindFile(csReadPath) == 0) // FindFile�֐��̖߂�l��0�ȊO�Ő��튮��
//	{
//		return NOT_FOUND_FILE;
//	}
//
//	CStdioFile cFile;
//	// Read���[�h�Ńt�@�C���I�[�v��
//	cFile.Open(csReadPath, CFile::modeRead);
//
//	// ��s���e�L�X�g�ǂݍ���
//	CString csReadLineText;
//
//	CArray<CStringArray*> CStringArrayList;
//	CStringArrayList.RemoveAll();
//
//	for (int I = 0; cFile.ReadString(csReadLineText); I++)
//	{
//		// CDataInfo�C���X�^���X�̍쐬
//		CDataInfo* cDataInfo = new CDataInfo();
//		m_pacDataInfo->Add(cDataInfo);
//		// �J�n�����ʒu�̏�����
//		int nStart = 0;
//		// �J���}�̕����ʒu
//		int nPos = -1;
//		// nPos��nStart����','�܂ł̕�����
//		nPos = csReadLineText.Find(',', nStart);
//		// �ǂݍ��݃f�[�^�̈ꎞ�ۑ��z��
//
//
//		CStringArray* CStrArray = new CStringArray();
//		CStrArray->RemoveAll();
//
//		CString ReadData;
//
//		// ��s���̃J���}��؂�̗v�f�𔲂��o��
//		for (int i = 0; nPos > -1; i++)
//		{
//
//
//			ReadData = csReadLineText.Mid(nStart, nPos - nStart);
//			nStart = nPos + 1;
//			// nPos�����̃J���}�ʒu�܂ňړ��B�J���}���Ȃ��ꍇ�AnPos��-1��Ԃ��B
//			nPos = csReadLineText.Find(',', nStart);
//			CStrArray->Add(ReadData);
//
//			if (nPos == -1)
//			{
//				ReadData = csReadLineText.Mid(nStart);
//				CStrArray->Add(ReadData);
//
//		
//				CStringArrayList.Add(CStrArray);
//
//				//				m_pacDataInfo->ElementAt(I)->SetData(
//
//				cDataInfo->SetData(
//					CStringArrayList.ElementAt(I)->ElementAt(0),
//					CStringArrayList.ElementAt(I)->ElementAt(1),
//					CStringArrayList.ElementAt(I)->ElementAt(2),
//					CStringArrayList.ElementAt(I)->ElementAt(3),
//					CStringArrayList.ElementAt(I)->ElementAt(4),
//					CStringArrayList.ElementAt(I)->ElementAt(5),
//					CStringArrayList.ElementAt(I)->ElementAt(6),
//					CStringArrayList.ElementAt(I)->ElementAt(7));
//
//				delete CStringArrayList.ElementAt(I);
//			}
//		}
//	}
//	cFile.Close();
//    return SUCCESS;
//}

/// <summary>
/// csv�t�@�C���̓ǂݍ��ݎ��s�֐�
/// </summary>
/// <param name="cReadPath">�ǂݍ��݃p�X</param>
/// <returns>0:�����@0�ȊO:���s</returns>
int CDataManagement::ReadFileData(TCHAR cReadPath[MAX_PATH])
{
	try
	{
		// �s��
		int nRowNum = 0;

		// ��ʂɓ��͂��ꂽ�p�X��CString�ɕϊ�
		CString csReadPath = cReadPath;
		// �C���X�^���X�̐���
		CFileFind cFileFind;

		// ���̓t�@�C�������݂��邩�m�F
		if (cFileFind.FindFile(csReadPath) == 0) // FindFile�֐��̖߂�l��0�ȊO�Ő��튮��
		{
			throw NOT_FOUND_FILE;
		}

		CStdioFile cFile;
		// Read���[�h�Ńt�@�C���I�[�v��
		cFile.Open(csReadPath, CFile::modeRead);

		// ��s���e�L�X�g�ǂݍ���CArray
		CArray<CString> CSReadLineTexArray;

		// ��s���̃e�L�X�g�i�[buffer
		CString csReadLineText;

		// 
		CArray<CStringArray*> CStringArrayList;
		CStringArrayList.RemoveAll();

		// �ǂݎ��f�[�^���s���ɕ������A�i�[
		for (int i = 0; cFile.ReadString(csReadLineText); i++)
		{
			CSReadLineTexArray.Add(csReadLineText);

			// �s���̃J�E���g
			nRowNum++;
		}

		cFile.Close();

		// �e�s�Ɋ܂܂��J���}������s�ڂ̃J���}���Ɠ�����check����
		for (int i = 0; i < nRowNum; i++)
		{
			int nCommaCount = this->CountCommaOcuurence(CSReadLineTexArray.ElementAt(i));
			// ��s�ڂ̏ꍇ�A�J���}����CDataInfo�N���X�̐ÓI�����o�ϐ��ɕۑ�����B
			if (i == 0)
			{
				CDataInfo::SetItemNum(nCommaCount);
			}
			// i�s�ڂ̃J���}����m_snItemNum�Ɠ���������r
			if (CDataInfo::m_snItemNum != nCommaCount)
				throw CSV_FORMAT_ERROR;
		}

		// ���ȍ~������

		// CArray<CDataInfo>�̃C���X�^���X���쐬����Ă���΁Anew���Ȃ��B
		if (m_pacDataInfo == nullptr)
		{
			m_pacDataInfo = new CArray<CDataInfo*>();
			m_pacDataInfo->RemoveAll();
		}

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

			CStringArray* CStrArray = new CStringArray();
			CStrArray->RemoveAll();

			CString ReadData;

			// ��s���̃J���}��؂�̗v�f�𔲂��o��
			for (int i = 0; nPos > -1; i++)
			{
				ReadData = csReadLineText.Mid(nStart, nPos - nStart);
				nStart = nPos + 1;
				// nPos�����̃J���}�ʒu�܂ňړ��B�J���}���Ȃ��ꍇ�AnPos��-1��Ԃ��B
				nPos = csReadLineText.Find(',', nStart);
				CStrArray->Add(ReadData);

				if (nPos == -1)
				{
					ReadData = csReadLineText.Mid(nStart);
					CStrArray->Add(ReadData);


					CStringArrayList.Add(CStrArray);

					//				m_pacDataInfo->ElementAt(I)->SetData(

					cDataInfo->SetData(
						CStringArrayList.ElementAt(I)->ElementAt(0),
						CStringArrayList.ElementAt(I)->ElementAt(1),
						CStringArrayList.ElementAt(I)->ElementAt(2),
						CStringArrayList.ElementAt(I)->ElementAt(3),
						CStringArrayList.ElementAt(I)->ElementAt(4),
						CStringArrayList.ElementAt(I)->ElementAt(5),
						CStringArrayList.ElementAt(I)->ElementAt(6),
						CStringArrayList.ElementAt(I)->ElementAt(7));

					delete CStringArrayList.ElementAt(I);
				}
			}
		}
		cFile.Close();
		return SUCCESS;
	}
	catch (int i)
	{
		return i;
	}
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

	if (m_pacDataInfo == nullptr)
	{
		return NO_DATAINFO;
	}


	// �ǉ����ꂽ�f�[�^�̍s���������[�v
	for (int i = 0; i < m_pacDataInfo->GetCount(); i++)
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
	// �I�u�W�F�N�g�̐���
	TCHAR* szCsvData = new TCHAR[cFile.GetLength()];
	memset(szCsvData, NULL, cFile.GetLength());

	if (cFile.Read(szCsvData, (UINT)cFile.GetLength()) <= 0)
	{
		// CSV�̃f�[�^����
		return NO_CSV_DATA;
	}

	cFile.Close();

	// �f�[�^���̃����o�ϐ�����������Ԃ̏ꍇnew����
	if (m_pacDataInfo == nullptr)
	{
		m_pacDataInfo = new CArray<CDataInfo*>();
		m_pacDataInfo->RemoveAll();
	}

	CString CStr = szCsvData;
	// �I�u�W�F�N�g�̊J��
	delete[](szCsvData);

	int crLfNum1 = 0;
	int crLfNum2 = 0;

	// �C���X�^���X�̐���
	CArray<CStringArray*> CStringArrayList;
	CStringArrayList.RemoveAll();

	while (true)
	{
		// �I�u�W�F�N�g�̐���
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
			CStr1 = CStr.Mid(crLfNum1, crLfNum2 + 1 - crLfNum1);
		}

		// ���s�R�[�h���폜
		CStr1.Replace(_T("\r\n"), _T(""));

		// �J���}��؂�ŕ���p
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
		// CDataInfo�I�u�W�F�N�g�̐���
		CDataInfo* cDataInfo = new CDataInfo();
		m_pacDataInfo->Add(cDataInfo);
		// 
//	}

		cDataInfo->SetData(
			CStringArrayList.ElementAt(i)->ElementAt(0),
			CStringArrayList.ElementAt(i)->ElementAt(1),
			CStringArrayList.ElementAt(i)->ElementAt(2),
			CStringArrayList.ElementAt(i)->ElementAt(3),
			CStringArrayList.ElementAt(i)->ElementAt(4),
			CStringArrayList.ElementAt(i)->ElementAt(5),
			CStringArrayList.ElementAt(i)->ElementAt(6),
			CStringArrayList.ElementAt(i)->ElementAt(7));

		// CStringArray�̗v�f�I�u�W�F�N�g��j��
		CStringArray* pCStringArray = CStringArrayList.GetAt(i);
		pCStringArray->RemoveAll();
		delete pCStringArray;

	}

	CStringArrayList.RemoveAll();
	return SUCCESS;
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
		char ch = cstr[i]; // �f�o�b�O�p
		if (cstr[i] == ',')
			nCommaOcuurence++;
	}

	return nCommaOcuurence;
}
