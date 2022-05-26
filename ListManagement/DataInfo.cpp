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

void CDataInfo::SetData(CString nId, CString csFirstName, CString csLastName, CString nAge, CString eSex, CString nHeight, CString nWeight, CString csFrom)
{
	
	m_nId = _ttoi(nId);
	m_csFirstName = csFirstName;
	m_csLastName = csLastName;
	m_nAge = _ttoi(nAge);
	if (eSex == "男")
		m_eSex = ESex::MAN;
	else if (eSex == "女")
		m_eSex = ESex::WOMAN;
	else
		m_eSex = ESex::OTHER;
	m_nHeight = _ttoi(nHeight);
	m_nWeight = _ttoi(nWeight);
	m_csFrom = csFrom;
	
	/*
	m_tDataInfo.nId = _ttoi(nId);
	m_tDataInfo.csFirstName = csFirstName;
	m_tDataInfo.csLastName = csLastName;
	m_tDataInfo.nAge = _ttoi(nAge);
	if (eSex == "男")
		m_tDataInfo.eSex = ESex::MAN;
	else if (eSex == "女")
		m_tDataInfo.eSex = ESex::WOMAN;
	else
		m_tDataInfo.eSex = ESex::OTHER;
	m_tDataInfo.nHeight = _ttoi(nHeight);
	m_tDataInfo.nWeight = _ttoi(nWeight);
	m_tDataInfo.csFrom = csFrom;
	*/
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

CArray<CDataInfo*>* CDataInfo::Getm_pacDataInfo_h()
{
	return m_pacDataInfo_h;
}

void CDataInfo::Setm_pacDataInfo_h(CArray<CDataInfo*>* pacDataInfo)
{
	m_pacDataInfo_h = pacDataInfo;
}

