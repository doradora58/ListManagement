#include "pch.h"
#include "DataInfo.h"



/// <summary>
/// �R���X�g���N�^
/// </summary>
CDataInfo::CDataInfo()
{
	
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CDataInfo::~CDataInfo()
{
}

void CDataInfo::SetData(int nId, CString csFirstName, CString csLastName, int nAge, ESex eSex, int nHeight, int nWeight, CString csFrom)
{
	m_nId = nId;
	m_csFirstName = csFirstName;
	m_csLastName = csLastName;
	m_nAge = nAge;
	m_eSex = eSex;
	m_nHeight = nHeight;
	m_nWeight = nWeight;
	m_csFrom = csFrom;
}

void CDataInfo::GetData(int* nId, CString* csFirstName, CString* csLastName, int* nAge, ESex* eSex, int* nHeight, int* nWeight, CString* csFrom)
{

}

void CDataInfo::GetData()
{
	
	return m_csFirstName;
}
