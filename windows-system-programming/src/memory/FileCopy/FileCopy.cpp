// FileCopy.cpp : 동기 파일 입출력 함수를 통한 파일 복사
//

#include <iostream>
#include <stdio.h>
#include <windows.h>

int main()
{
	::_wsetlocale(LC_ALL, L"korean");

	HANDLE hFileSource = NULL, hFileTarget = NULL;

	hFileSource = ::CreateFile(TEXT("C:\\TEST\\\Sleep Away.zip"),
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

	hFileTarget = CreateFile(TEXT("C:\\TEST\\Sleep Away - copy.zip"),
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (hFileTarget == INVALID_HANDLE_VALUE)
	{
		wprintf(L"Failed to opne target file [ERROR CODE: %d]\n",
			::GetLastError());

		::CloseHandle(hFileSource);
		return 0;
	}

	LARGE_INTEGER llFileSize = { 0 };
	LONGLONG llTotalReadSize = 0;
	DWORD dwReadSize = 0, dwWriteSize = 0;
	BOOL bResult = FALSE;
	BYTE byBuffer[65536];

	if (!::GetFileSizeEx(hFileSource, &llFileSize))
	{
		wprintf(L"원본 파일의 크기를 알 수 없습니다.\n");
		::CloseHandle(hFileSource);
		::CloseHandle(hFileTarget);
		return 0;
	}

	for (LONGLONG i = 0; i < llFileSize.QuadPart; i += dwReadSize)
	{
		::ZeroMemory(byBuffer, 65536);
		bResult = ReadFile(hFileSource,
			byBuffer, 65536, &dwReadSize, NULL);
		if (!bResult)
		{
			wprintf(L"Failed to read source file [ERROR CODE: %d]\n",
				::GetLastError());
			break;
		}
		else if (bResult && dwReadSize == 0)
			break;

		llTotalReadSize += dwReadSize;
		wprintf(L"%I64d%%\n",
			llTotalReadSize * 100 / llFileSize.QuadPart);

		if (!::WriteFile(hFileTarget,
			byBuffer, dwReadSize, &dwWriteSize, NULL) ||
			dwReadSize != dwWriteSize)
		{
			wprintf(L"Failed to write target file [ERRO CODE: %d]\n",
				::GetLastError());
			break;
		}
	}

	_putws(L"Complete\n");
	::CloseHandle(hFileSource);
	::CloseHandle(hFileTarget);
	return 0;
}
