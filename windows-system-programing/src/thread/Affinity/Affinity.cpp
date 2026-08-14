// Affinity.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <process.h>

UINT WINAPI ThreadFunction(LPVOID pParam)
{
	int nTmp = 0;
	while (1)
	{
		++nTmp;
	}

	return 0;
}

int main()
{
	UINT nThreadId = 0;
	HANDLE hThread = (HANDLE)::_beginthreadex(
		NULL,
		0,
		ThreadFunction,
		NULL,
		0,
		&nThreadId
	);
	if (hThread == NULL)
	{
		std::cout << "ERROR : Failed to begin thread" << std::endl;
		Sleep(5000);
	}

	for (int i = 0;i < 8;++i)
	{
		::SetThreadAffinityMask(hThread, 0x00000001 << i);
		::Sleep(5000);
	}

	::WaitForSingleObject(hThread, INFINITE);
	::CloseHandle(hThread);
}
