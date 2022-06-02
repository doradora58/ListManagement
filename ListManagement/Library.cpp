#include "pch.h"
#include "Library.h"



std::string CParam::GetConfigString(const std::string& filePath, const char* pSectionName, const char* pKeyName)
{
    if (filePath.empty()) {
        return "";
    }
    std::array<char, MAX_PATH> buf = {};
    GetPrivateProfileString(pSectionName, pKeyName, "", &buf.front(), static_cast<DWORD>(buf.size()), filePath.c_str());
    return &buf.front();
}


CParam* CParam::pParam = nullptr;