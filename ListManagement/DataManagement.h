#pragma once
#include "DataInfo.h"

#define NOT_FOUND_FILE -1 // ���̓t�@�C�������݂��Ȃ��G���[
#define FILE_OPEN_FAILED -2 // �t�@�C����������Ȃ��G���[
#define CSV_COLUMNS_NUM 8 // csv�t�@�C���̗�
#define SUCCESS 0 // ��������
#define NO_CSV_DATA -3 // CSV�f�[�^���Ȃ����߃G���[
#define NO_DATAINFO -4 // �f�[�^���Ƀf�[�^���Ȃ����߃G���[
#define CSV_FORMAT_ERROR -5

class CDataManagement
{


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
	int ReadFileData(TCHAR cReadPath[MAX_PATH]);


	/// <summary>
	/// �f�[�^�̏����o�������s
	/// </summary>
	/// <param name="cWritePath">�����o����t�H���_�̐e�p�X</param>
	/// <param name="cFileName">�����o���p�̃t�@�C����</param>
	/// <param name="cDataInfo">�����o���p�f�[�^</param>
	/// <returns>0�F�����@0�F�ȊO���s</returns>
	int WriteData(TCHAR cWritePath[MAX_PATH], TCHAR cFileName[_MAX_FNAME]);

	void GetDataInfo(CArray<CDataInfo*>& pacDataInfo);

	/// <summary>
	/// �t�@�C�������擾����
	/// </summary>
	/// <returns>�t�@�C����</returns>
	CString Getm_csFileName();

	/// <summary>
	/// �o�͐�p�X���擾����
	/// </summary>
	/// <returns>�o�͐�p�X</returns>
	CString Getm_csReadPath();

	// 
	int CountCommaOcuurence(CString& cstr) const;


	//***********�B�|��������*********
	int ReadFileDataKK(TCHAR cReadPath[MAX_PATH]);
	int WriteDataKK(TCHAR cWritePath[MAX_PATH], TCHAR cFileName[_MAX_FNAME]);
	//********************************

// �������private�ɂ�����
//private:
	// **********�����o�ϐ�**********
	//CString m_csWritePath; // �t�@�C���o�͐�e�t�H���_�p�X
	CString m_csFileName; // �t�@�C���o�͐�t�@�C����

	CString m_csReadPath; // �ǂݍ��ރt�@�C���̊��S�p�X

};