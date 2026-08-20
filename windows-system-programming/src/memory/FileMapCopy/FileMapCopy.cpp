// FileMapCopy.cpp : 파일 매핑을 통해 메모리 추상화를 하여 받은 포인터를 이용해 파일을 복사하는 코드 예제
//

#include <iostream>
#include <stdio.h>
#include <windows.h>

int main()
{
	HANDLE hFile = ::CreateFile(
		TEXT("C:\\Test\\Sleep Away.zip"),
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	DWORD size = GetFileSize(hFile, NULL);

	HANDLE hMap = ::CreateFileMapping(
		hFile, NULL, PAGE_READWRITE, 0, size, NULL);
	if (hMap == NULL)
	{
		wprintf(L"Failed to create file mapping obj [ERROR CODE: %d]\n",
			::GetLastError());

		::CloseHandle(hFile);
		return 0;
	}

	char* pszMemory = (char*)::MapViewOfFile(
		hMap, FILE_MAP_ALL_ACCESS, 0, 0, size
	);
	if (pszMemory == NULL)
	{
		::CloseHandle(hMap);
		::CloseHandle(hFile);
		return 0;
	}

	HANDLE hFile2 = ::CreateFile(
		TEXT("C:\\Test\\Sleep Away2.zip"),
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	DWORD size2 = GetFileSize(hFile, NULL);

	HANDLE hMap2 = ::CreateFileMapping(
		hFile2, NULL, PAGE_READWRITE, 0, size2, NULL);
	if (hMap2 == NULL)
	{
		wprintf(L"Failed to create file mapping obj [ERROR CODE: %d]\n",
			::GetLastError());

		::CloseHandle(hFile2);
		return 0;
	}

	char* pszMemory2 = (char*)::MapViewOfFile(
		hMap2, FILE_MAP_ALL_ACCESS, 0, 0, size2
	);
	if (pszMemory2 == NULL)
	{
		::CloseHandle(hMap2);
		::CloseHandle(hFile2);
		return 0;
	}

	memcpy(pszMemory2, pszMemory, size);

	::UnmapViewOfFile(pszMemory);
	::CloseHandle(hMap);
	::CloseHandle(hFile);

	::UnmapViewOfFile(pszMemory2);
	::CloseHandle(hMap2);
	::CloseHandle(hFile2);
}
