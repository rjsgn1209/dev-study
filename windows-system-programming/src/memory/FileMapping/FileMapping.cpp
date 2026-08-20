// FileMappoing.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
#include <windows.h>

int main()
{
	HANDLE hFile = ::CreateFile(
		TEXT("C:\\Test\\MYFILE.TXT"),
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	::SetFilePointer(hFile, 1024, NULL, FILE_BEGIN);

	HANDLE hMap = ::CreateFileMapping(
		hFile, NULL, PAGE_READWRITE, 0, 1024, NULL);
	if (hMap == NULL)
	{
		wprintf(L"Failed to create file mapping obj [ERROR CODE: %d]\n",
			::GetLastError());

		::CloseHandle(hFile);
		return 0;
	}

	char* pszMemory = (char*)::MapViewOfFile(
		hMap, FILE_MAP_ALL_ACCESS, 0, 0, 1024
	);
	if (pszMemory == NULL)
	{
		::CloseHandle(hMap);
		::CloseHandle(hFile);
		return 0;
	}

	strcpy_s(pszMemory, 1024, "Hello, Memory Mapped File!");

	::UnmapViewOfFile(pszMemory);
	::CloseHandle(hMap);

	::CloseHandle(hFile);
}
