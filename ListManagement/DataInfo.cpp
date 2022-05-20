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
	nId = m_nId;
	csFirstName = m_csFirstName;
	csLastName = m_csLastName;
	nAge = m_nAge;
	eSex = m_eSex;
	nHeight = m_nHeight;
	nWeight = m_nWeight;
	csFrom = m_csFrom;


}


