#pragma once

// 
enum ESex
{
	MAN = 0, // �j
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
		eSex = ESex::OTHER;
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

	void SetData(CString nId, CString csFirstName, CString csLastName, CString nAge, CString eSex, CString nHeight, CString nWeight, CString csFrom);

	void SetData(TDataInfo tDataInfo);

	void GetData(int* nId, CString* csFirstName, CString* csLastName, int* nAge, ESex* eSex, int* nHeight, int* nWeight, CString* csFrom);

	void GetData(TDataInfo* ptDataInfo);

	/// <summary>
	/// m_pacDataInfo�̃|�C���^���擾����
	/// </summary>
	/// <returns>m_pacDataInfo</returns>
	CArray<CDataInfo*>* Getm_pacDataInfo_h();

	/// <summary>
	/// m_pacDataInfo�̃|�C���^��
	/// </summary>
	/// <param name="pacDataInfo"></param>
	void Setm_pacDataInfo_h(CArray<CDataInfo*>* pacDataInfo);

	TDataInfo m_tDataInfo;

	int m_nId; // ID
	CString m_csFirstName; // ���O�i���j
	CString m_csLastName; // ���O�i���j
	int m_nAge; // �N��
	ESex m_eSex; // ���� 
	int m_nHeight; // �g��
	int m_nWeight; // �̏d
	CString m_csFrom; // �o�g�n

	CArray<CDataInfo*>* m_pacDataInfo_h; // CDataInfo*�^CArray�̃|�C���^
};
