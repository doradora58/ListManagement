#include "pch.h"
#include "DataInfo.h"



/// <summary>
/// コンストラクタ
/// </summary>
CDataInfo::CDataInfo()
{
	m_tDataInfo.nId = 0;
	m_tDataInfo.csFirstName = "";
	m_tDataInfo.csLastName = "";
	m_tDataInfo.nAge = 0;
	m_tDataInfo.eSex = ESex::MAN;
	m_tDataInfo.nHeight = 0;
	m_tDataInfo.nWeight =0;
	m_tDataInfo.csFrom = "";

	m_nId = 0;
	m_csFirstName = "";
	m_csLastName = "";
	m_nAge = 0;
	m_eSex = ESex::MAN;
	m_nHeight = 0;
	m_nWeight = 0;
	m_csFrom ="";

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

void CDataInfo::SetData(TDataInfo tDataInfo)
{
	m_tDataInfo = tDataInfo;
	
}

void CDataInfo::GetData(int* nId, CString* csFirstName, CString* csLastName, int* nAge, ESex* eSex, int* nHeight, int* nWeight, CString* csFrom)
{
	*nId = m_nId;
	*csFirstName = m_csFirstName;
	*csLastName = m_csLastName;
	*nAge = m_nAge;
	*eSex = m_eSex;
	*nHeight = m_nHeight;
	*nWeight = m_nWeight;
	*csFrom = m_csFrom;


}

void CDataInfo::GetData(TDataInfo* ptDataInfo)
{
	*ptDataInfo = m_tDataInfo;
}


