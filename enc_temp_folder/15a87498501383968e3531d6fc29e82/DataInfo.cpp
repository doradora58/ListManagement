#include "pch.h"
#include "DataInfo.h"



/// <summary>
/// �R���X�g���N�^
/// </summary>
CDataInfo::CDataInfo()
{
	m_ptDataInfo = new TDataInfo();
	m_ptDataInfo->csFirstName = _T("aaa");
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
CDataInfo::~CDataInfo()
{
}
