#pragma once
#define NOT_FOUND_FILE -1 // ���̓t�@�C�������݂��Ȃ��G���[

// csv�ǂݍ��݃N���X
class CReadFile
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CReadFile();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~CReadFile();


	/// <summary>
	/// csv�t�@�C���̓ǂݍ��ݎ��s�֐�
	/// </summary>
	/// <param name="cReadPath">�ǂݍ��݃p�X</param>
	/// <returns>0:�����@0�ȊO:���s</returns>
	int ReadFileData(wchar_t cReadPath[MAX_PATH]);



	// **********�����o�ϐ�**********

	CString m_csReadPath; // �ǂݍ��ރt�@�C���̊��S�p�X

};