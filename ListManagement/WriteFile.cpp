#include "pch.h"
#include "WriteFile.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="cWritePath">CSV�����o���p�̃p�X</param>
CWriteFile::CWriteFile(wchar_t cWritePath[MAX_PATH],wchar_t cFileName[_MAX_FNAME])
{

	CDataInfo::m_csWritePath = cWritePath;
}

CWriteFile::CWriteFile(wchar_t cWritePath[MAX_PATH], wchar_t cFIleName[_MAX_FNAME])
{
}

/// <summary>
/// �f�X�X�g���N�^
/// </summary>
CWriteFile::~CWriteFile()
{
}
