#include "pch.h"
#include "WriteFile.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="cWritePath">CSV書き出し用のパス</param>
CWriteFile::CWriteFile(wchar_t cWritePath[MAX_PATH],wchar_t cFileName[_MAX_FNAME])
{

	CDataInfo::m_csWritePath = cWritePath;
}

CWriteFile::CWriteFile(wchar_t cWritePath[MAX_PATH], wchar_t cFIleName[_MAX_FNAME])
{
}

/// <summary>
/// デスストラクタ
/// </summary>
CWriteFile::~CWriteFile()
{
}
