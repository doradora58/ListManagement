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

CString CDataInfo::GetFirstName()
{
	return m_csFirstName;
}
