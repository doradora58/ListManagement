#include "pch.h"
#include "DataInfo.h"



/// <summary>
/// コンストラクタ
/// </summary>
CDataInfo::CDataInfo()
{
	m_ptDataInfo = new TDataInfo();
	m_ptDataInfo->csFirstName = _T("aaa");
}

/// <summary>
/// デストラクタ
/// </summary>
CDataInfo::~CDataInfo()
{
}
