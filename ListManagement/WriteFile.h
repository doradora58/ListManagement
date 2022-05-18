#pragma once
#include "DataInfo.h"

#define MAX_TEXT 100 // �e�L�X�g�̍ő�l

// CSV�t�@�C�������o���N���X
class CWriteFile
{
public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="cWritePath">CSV�����o���p�̃p�X</param>
	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="cWritePath"></param>
	/// <param name="cFIleName"></param>
	CWriteFile(wchar_t cWritePath[MAX_PATH], wchar_t cFIleName[_MAX_FNAME]);

	/// <summary>
	/// �f�X�X�g���N�^
	/// </summary>
	~CWriteFile();

	/// <summary>
	/// CSV�̏����o�������s
	/// </summary>
	/// <param name="cWritePath">�����o����t�H���_�̐e�p�X</param>
	/// <param name="cFileName">�����o���p�̃t�@�C����</param>
	/// <param name="cText">�����o�����e</param>
	/// <returns>0�F�����@0�F�ȊO���s</returns>
	int WriteCsvText(wchar_t cWritePath[MAX_PATH], wchar_t cFileName[_MAX_FNAME],wchar_t cText[MAX_TEXT]);




	// **********�����o�ϐ�**********
	CString m_csWritePath; // �t�@�C���o�͐�e�t�H���_�p�X
	CString m_csFileName; // �t�@�C���o�͐�t�@�C����



};