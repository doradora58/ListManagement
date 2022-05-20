#pragma once
#include "DataInfo.h"

class CDataManagement {


public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CDataManagement();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~CDataManagement();


	/// <summary>
	/// csv�t�@�C���̓ǂݍ��ݎ��s�֐�
	/// </summary>
	/// <param name="cReadPath">�ǂݍ��݃p�X</param>
	/// <returns>0:�����@0�ȊO:���s</returns>
	int ReadFileData(wchar_t cReadPath[MAX_PATH]);


	/// <summary>
	/// �f�[�^�̏����o�������s
	/// </summary>
	/// <param name="cWritePath">�����o����t�H���_�̐e�p�X</param>
	/// <param name="cFileName">�����o���p�̃t�@�C����</param>
	/// <param name="cDataInfo">�����o���p�f�[�^</param>
	/// <returns>0�F�����@0�F�ȊO���s</returns>
	int WriteData(wchar_t cWritePath[MAX_PATH], wchar_t cFileName[_MAX_FNAME], TDataInfo tDataInfo);




	// **********�����o�ϐ�**********
	CString m_csWritePath; // �t�@�C���o�͐�e�t�H���_�p�X
	CString m_csFileName; // �t�@�C���o�͐�t�@�C����

	CString m_csReadPath; // �ǂݍ��ރt�@�C���̊��S�p�X
	TDataInfo* m_ptDataInfo;

};