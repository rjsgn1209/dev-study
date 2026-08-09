// CreateProcessSample.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <Windows.h>
#include <lm.h>
#include <Sddl.h>
#include <Psapi.h>

void CreateSample01()
{
	STARTUPINFO si;
	::ZeroMemory(&si, sizeof(STARTUPINFO));

	PROCESS_INFORMATION pi;
	::ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));

	TCHAR szBuffer[_MAX_FNAME] = TEXT("notepad.exe");
	if (::CreateProcess(NULL,
		szBuffer,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi))
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
}

int main()
{
	CreateSample01();
}
