#include "pch.h"
#include "WriteFile.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="cWritePath">CSV�����o���p�̃p�X</param>
CWriteFile::CWriteFile(wchar_t cWritePath[MAX_PATH],wchar_t cFileName[_MAX_FNAME])
{

	m_csWritePath = cWritePath;

}


/// <summary>
/// �f�X�X�g���N�^
/// </summary>
CWriteFile::~CWriteFile()
{
}

/// <summary>
/// CSV�̏����o�������s
/// </summary>
/// <param name="cWritePath">�����o����t�H���_�̐e�p�X</param>
/// <param name="cFileName">�����o���p�̃t�@�C����</param>
/// <param name="cText">�����o�����e</param>
/// <returns>0�F�����@0�F�ȊO���s</returns>
int CWriteFile::WriteCsvText(wchar_t cWritePath[MAX_PATH], wchar_t cFileName[_MAX_FNAME], wchar_t cText[MAX_TEXT])
{

	return 0;
}
