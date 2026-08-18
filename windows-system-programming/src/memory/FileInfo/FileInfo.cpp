// FileInfo.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <windows.h>
#include <stdio.h>

void LoadDiskInfo(const TCHAR* pszPath)
{
	TCHAR szVolName[MAX_PATH] = { 0 };
	TCHAR szFileSys[MAX_PATH] = { 0 };
	TCHAR szRoot[MAX_PATH] = { 0 };
	DWORD dwSericalNum = 0, dwMaxCompLen = 0, dwSysFlag = 0;

	memcpy(szRoot, pszPath, sizeof(TCHAR) * 3);

	::GetVolumeInformation(szRoot, szVolName, MAX_PATH, &dwSericalNum,
		&dwMaxCompLen, &dwSysFlag, szFileSys, MAX_PATH);

	wprintf(TEXT("Volume name : %s File System : %s\n"),
		szVolName, szFileSys);

	ULARGE_INTEGER llAvailableSpace = { 0 };
	ULARGE_INTEGER llTotalSpace = { 0 };
	ULARGE_INTEGER llFreeSpace = { 0 };

	if (::GetDiskFreeSpaceEx(szRoot,
		&llAvailableSpace, &llTotalSpace, &llFreeSpace))
	{
		wprintf(TEXT(" (Disk free space: %I64u/%I64u GB)\n"),
			llFreeSpace.QuadPart / (1024 * 1024 * 1024),
			llTotalSpace.QuadPart / (1024 * 1024 * 1024));
	}
}

void LoadFileList(const TCHAR* pszPath)
{
	TCHAR szPath[MAX_PATH] = { 0 };
	wsprintf(szPath, TEXT("%s\\*.*"), pszPath);

	WIN32_FIND_DATA FindData;
	BOOL bResult = TRUE;
	::ZeroMemory(&FindData, sizeof(WIN32_FIND_DATA));

	HANDLE hFirstFile = ::FindFirstFile(
		(LPTSTR)(const TCHAR*)szPath, &FindData);
	while (bResult)
	{
		if (FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			wprintf(TEXT("[DIR] %s\n"), FindData.cFileName);
		else
			wprintf(TEXT("%s\n"), FindData.cFileName);

		bResult = ::FindNextFile(hFirstFile, &FindData);
	}

}

int main()
{
	::_wsetlocale(LC_ALL, TEXT("korean"));

	LoadDiskInfo(TEXT("C:\\"));
	LoadFileList(TEXT("C:\\"));

	TCHAR szCurDir[MAX_PATH] = { 0 };
	::GetCurrentDirectory(MAX_PATH, szCurDir);
	wprintf(TEXT("Current Directory: %s\n"), szCurDir);
}
