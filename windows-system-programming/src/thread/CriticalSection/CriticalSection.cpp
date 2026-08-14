// CriticalSection.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <process.h>

char* g_pszBuffer = NULL;
CRITICAL_SECTION g_cs;

void SetString(const char* pszData)
{
    ::EnterCriticalSection(&g_cs);
    if (g_pszBuffer != NULL)
    {
        free(g_pszBuffer);
        g_pszBuffer = (char*)malloc(64);
        sprintf_s(g_pszBuffer, 64, "%s", pszData);
    }
    else
    {
        g_pszBuffer = (char*)malloc(64);
        sprintf_s(g_pszBuffer, 64, "%s", pszData);
    }
    ::LeaveCriticalSection(&g_cs);
}

BOOL GetString(char* pszData)
{
    ::EnterCriticalSection(&g_cs);
    if (pszData != NULL)
    {
        sprintf_s(pszData, 64, "%s", g_pszBuffer);
        free(g_pszBuffer);
        g_pszBuffer = NULL;

        ::LeaveCriticalSection(&g_cs);
        return TRUE;
    }    

    ::LeaveCriticalSection(&g_cs);
    return FALSE;
}

UINT ThreadFunc1(LPVOID pParam)
{
    while (TRUE)
    {
        ::Sleep(1);
        SetString("ThreadFunc1");
    }
    return 0;
}

UINT ThreadFunc2(LPVOID pParam)
{
    while (TRUE)
    {
        ::Sleep(1);
        SetString("ThreadFunc2");
    }
    return 0;
}

int main()
{
    ::InitializeCriticalSection(&g_cs);

    UINT nThreadId = 0;
    HANDLE hThread = (HANDLE)::_beginthreadex(
        NULL,
        0,
        ThreadFunc1,
        NULL,
        0,
        &nThreadId
    );
    ::CloseHandle(hThread);

    hThread = (HANDLE)::_beginthreadex(
        NULL,
        0,
        ThreadFunc2,
        NULL,
        0,
        &nThreadId
    );

    char szBuffer[64];
    for (int i = 0; i < 5; i++)
    {
        ::Sleep(500);

        GetString(szBuffer);
        puts(szBuffer);
    }

    WaitForSingleObject(hThread, INFINITE);
    ::CloseHandle(hThread);

    ::DeleteCriticalSection(&g_cs);
    return 0;
}
