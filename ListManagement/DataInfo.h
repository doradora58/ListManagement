#pragma once

// 
enum ESex 
{
	MAN=0, // �j
	WOMAN, // ��
	OTHER //���̑�
};

// CSV�ǂݍ��ݍ\����
struct TDataInfo
{
public:
	int nId; // ID
	CString csFirstName; // �t�@�[�X�g�l�[��
	CString csLastName; // ���X�g�l�[��
	int nAge; // �N��
	ESex eSex; // ���� 
	int nHeight; // �g��
	int nWeight; // �̏d
	CString csPlace; // �o�g�n

};

class CDataInfo
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CDataInfo();


	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~CDataInfo();


};