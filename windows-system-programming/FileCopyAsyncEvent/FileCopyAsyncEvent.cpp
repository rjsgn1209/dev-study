// FileCopyAsyncEvent.cpp : 학습한 파일 매핑 기법과 비동기 파일 처리 이벤트 방식을 활용한 파일 쓰기 예제.
//

#include <iostream>
#include <stdio.h>
#include <Windows.h>

void CloseAll(char* pszMem, HANDLE hMap, HANDLE hSrc, HANDLE hDst)
{
    if (pszMem != NULL)
        ::UnmapViewOfFile(pszMem);
    if (hMap != NULL)
        ::CloseHandle(hMap);
    if (hSrc != NULL)
        ::CloseHandle(hSrc);
    if (hDst != NULL)
        ::CloseHandle(hDst);
}

int main()
{
    ::_wsetlocale(LC_ALL, L"korean");
    HANDLE hFileSource = NULL, hFileTarget = NULL;
    LARGE_INTEGER llFileSize = { 0 };
    HANDLE hMap = NULL;
    char* pszMemory = NULL;

    hFileSource = CreateFile(TEXT("C:\\Test\\Sleep Away.zip"),
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);
    if (hFileSource == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Failed to open source file [ERROR CODE : %d]\n",
            ::GetLastError());
        return 0;
    }

    if (!::GetFileSizeEx(hFileSource, &llFileSize))
    {
        wprintf(L"Failed to get source file size [ERROR CODE : %d]\n",
            ::GetLastError());
        CloseAll(NULL, NULL, hFileSource, NULL);
        return 0;
    }

    hMap = CreateFileMapping(hFileSource, NULL, PAGE_READONLY, 0,
        (DWORD)llFileSize.QuadPart, NULL);
    if (hMap == NULL)
    {
        wprintf(L"Failed to create file mapping obj [ERROR CODE : %d]\n",
            ::GetLastError());
        CloseAll(NULL, NULL, hFileSource, NULL);
        return 0;
    }

    pszMemory = (char*)::MapViewOfFile(hMap, FILE_MAP_READ, 0, 0,
        (DWORD)llFileSize.QuadPart);
    if (pszMemory == NULL)
    {
        CloseAll(NULL, hMap, hFileSource, NULL);
        return 0;
    }

    ::DeleteFile(TEXT("C:\\Test\\Sleep Away - copy.zip"));
    hFileTarget = ::CreateFile(TEXT("C:\\Test\\Sleep Away - copy.zip"),
        GENERIC_ALL,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED,
        NULL);
    if (hFileTarget == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Failed to open target file [ERROR CODE: %d\n",
            ::GetLastError());
        CloseAll(pszMemory, hMap, hFileSource, NULL);
        return 0;
    }

    LPOVERLAPPED pOverLapped = (LPOVERLAPPED)malloc(sizeof(OVERLAPPED));
    pOverLapped->OffsetHigh = 0;
    pOverLapped->Offset = 0;
    pOverLapped->hEvent = ::CreateEvent(NULL, FALSE, FALSE, NULL);

    DWORD dwWritten = 0;
    ::WriteFile(hFileTarget, pszMemory, (DWORD)llFileSize.QuadPart,
        &dwWritten, pOverLapped);
    if (::GetLastError() != ERROR_IO_PENDING)
    {
        wprintf(L"WriteFile [ERROR CODE: %d]", ::GetLastError());

        CloseAll(pszMemory, hMap, hFileSource, NULL);
        ::CloseHandle(pOverLapped->hEvent);
        free(pOverLapped);
        return 0;
    }

    if (::WaitForSingleObject(pOverLapped->hEvent, INFINITE) == WAIT_OBJECT_0)
        _putws(L"Complete!\n");

    CloseAll(pszMemory, hMap, hFileSource, hFileTarget);
    ::CloseHandle(pOverLapped->hEvent);
    free(pOverLapped);
    return 0;
}
