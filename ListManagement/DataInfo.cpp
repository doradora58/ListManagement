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

void CDataInfo::SetData(CString csFirstName)
{

	m_csFirstName = csFirstName;
}

CString CDataInfo::GetFirstName()
{
	
	return m_csFirstName;
}
