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

void CreateSample02()
{
	PROCESS_INFORMATION pi;
	::ZeroMemory(&pi, sizeof(pi));

	STARTUPINFO si;
	::ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(STARTUPINFO);	// CreateProcessAsUser 시 cb값이 STARUPINFO 사이즈가 맞는지 확인을 통해 정상 초기화된건지 판단함
	si.lpDesktop = (LPWSTR)TEXT("winsta0\\default");	// 프로세스가 생성될 윈도우 스테이션(winsta0)과 데스크톱(default)을 지정
	HANDLE hToken = NULL;
	HANDLE hProcess = NULL;

	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION,
		TRUE, ::GetCurrentProcessId());
	::OpenProcessToken(hProcess, TOKEN_ALL_ACCESS, &hToken);

	TCHAR szBuffer[_MAX_FNAME] = TEXT("notepad.exe");
	if (CreateProcessAsUser(
		hToken,
		NULL,
		szBuffer,
		NULL,
		NULL,
		TRUE,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si,
		&pi
	))
	{
		::CloseHandle(pi.hProcess);
		::CloseHandle(pi.hThread);
	}

	::CloseHandle(hToken);
	::CloseHandle(hProcess);
}

int main()
{
	//CreateSample01();
	CreateSample02();
}
