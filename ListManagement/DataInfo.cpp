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

void CDataInfo::SetFirstName(CString csFirstName)
{

	m_csFirstName = csFirstName;
}

void CDataInfo::GetData(int* nId, CString* csFirstName, CString* csLastName, int* nAge, ESex* eSex, int* nHeight, int* nWeight, CString* csFrom)
{

}

void CDataInfo::GetData()
{
	
	return m_csFirstName;
}
