#pragma once

// 
enum ESex 
{
	MAN=0, // �j
	WOMAN, // ��
	OTHER //���̑�
};

// �f�[�^���\����
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
	CString csFrom; // �o�g�n
	TDataInfo()
	{
		nId = 0;
		csFirstName = "";
		csLastName = "";
		nAge = 0;
		eSex = ESex::MAN;
		nHeight = 0;
		nWeight = 0;
		csFrom = "";

	}

};

// �f�[�^���N���X
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

	void SetFirstName(CString csFirstName);

	void GetData(int* nId, CString* csFirstName, CString* csLastName, int* nAge, ESex* eSex, int* nHeight, int* nWeight, CString* csFrom);

	int m_nId; // ID
	CString m_csFirstName; // �t�@�[�X�g�l�[��
	CString m_csLastName; // ���X�g�l�[��
	int m_nAge; // �N��
	ESex m_eSex; // ���� 
	int m_nHeight; // �g��
	int m_nWeight; // �̏d
	CString m_csFrom; // �o�g�n
};