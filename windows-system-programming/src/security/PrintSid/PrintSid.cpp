// PrintSid.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <Windows.h>
#include <lm.h>
#include <Sddl.h>
#include <Psapi.h>

void PrintSid()
{
    HANDLE hToken = NULL;
    HANDLE hProcess = NULL;

    hProcess = OpenProcess(
        PROCESS_QUERY_INFORMATION, TRUE,
        ::GetCurrentProcessId());
    ::OpenProcessToken(hProcess,
        TOKEN_ALL_ACCESS, &hToken);

    PTOKEN_USER pTokenUser = NULL;
    DWORD dwLength = 0;
    ::GetTokenInformation(hToken,
        TokenUser, (LPVOID)pTokenUser, 0, &dwLength);
    pTokenUser = (PTOKEN_USER)HeapAlloc(
        ::GetProcessHeap(), HEAP_ZERO_MEMORY, dwLength
    );

    if (::GetTokenInformation(hToken,
        TokenUser, pTokenUser, dwLength, &dwLength))
    {
        TCHAR* pszBuffer = NULL;
        ::ConvertSidToStringSid(pTokenUser->User.Sid, &pszBuffer);

        wprintf(L"SID: %s\n", pszBuffer);
        ::LocalFree((HLOCAL)pszBuffer);
    }
    else
    {
        wprintf(L"ERROR NUMBER : %d", ::GetLastError());
    }

    ::CloseHandle(hToken);
    ::CloseHandle(hProcess);
    ::HeapFree(::GetProcessHeap(), 0, (LPVOID)pTokenUser);
}

int main()
{
    PrintSid();
}
