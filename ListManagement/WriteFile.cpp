#include "pch.h"
#include "WriteFile.h"
#include "DataInfo.h"
#include "ReadFile.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="cWritePath">CSV�����o���p�̃p�X</param>
CWriteFile::CWriteFile(wchar_t cWritePath[MAX_PATH],wchar_t cFileName[_MAX_FNAME])
{
	m_csWritePath = cWritePath;
	m_csFileName = cFileName;
}


/// <summary>
/// �f�X�X�g���N�^
/// </summary>
CWriteFile::~CWriteFile()
{
	m_csWritePath = "";
	m_csFileName = "";
}
/// <summary>
/// �t�@�C���Ƀf�[�^�̏����o�������s
/// </summary>
/// <param name="cWritePath">�����o����t�H���_�̃p�X</param>
/// <param name="cFileName">�����o���p�̃t�@�C����</param>
/// <param name="cDataInfo">�����o���p�f�[�^</param>
/// <returns>0�F�����@0�F�ȊO���s</returns>
int CWriteFile::WriteData(wchar_t cWritePath[MAX_PATH], wchar_t cFileName[_MAX_FNAME], TDataInfo tDataInfo)
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

