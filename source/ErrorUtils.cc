#include "ErrorUtils.h"

void ErrorUtils::PrintLastError() {
    DWORD errorCode = GetLastError();
    LPSTR errorMessage = nullptr;

    DWORD dwLanguageId = MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED);

    FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        nullptr, errorCode, dwLanguageId,
        (LPSTR)&errorMessage, 0, nullptr);

    if (errorMessage != nullptr) {
        printf("Error %lu: %s\n", errorCode, errorMessage);
        LocalFree(errorMessage);
    }
    else {
        wprintf(L"Error %lu: Unable to retrieve error message.\n", errorCode);
    }
}
