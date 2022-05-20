#include "pch.h"
#include "DataInfo.h"



/// <summary>
/// コンストラクタ
/// </summary>
CDataInfo::CDataInfo()
{
	
}

/// <summary>
/// デストラクタ
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
	nId = &m_nId;
	csFirstName = &m_csFirstName;
	csLastName = &m_csLastName;
	nAge = &m_nAge;
	eSex = &m_eSex;
	nHeight = &m_nHeight;
	nWeight = &m_nWeight;
	csFrom = &m_csFrom;


}


