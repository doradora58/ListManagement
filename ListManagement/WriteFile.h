#pragma once
#include "DataInfo.h"

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




	// **********�����o�ϐ�**********
	CString m_csWritePath; // �t�@�C���o�͐�e�t�H���_�p�X
	CString m_csFileName; // �t�@�C���o�͐�t�@�C����



};