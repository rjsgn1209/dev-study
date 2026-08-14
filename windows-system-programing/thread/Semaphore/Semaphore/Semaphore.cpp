// Semaphore.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
#include <process.h>
#include <Windows.h>

HANDLE g_hSema;
TCHAR g_StringList[10][64] = { 0 };

UINT WINAPI ThreadSemaphore(LPVOID pParam)
{
	int nIndex = (int)pParam;

	while (true)
	{
		::wsprintf(g_StringList[nIndex],
			TEXT("%d thread is waiting!"), nIndex);
		::Sleep(500);

		DWORD dwResult = ::WaitForSingleObject(g_hSema, INFINITE);
		::wsprintf(g_StringList[nIndex],
			TEXT("##%d thread is selected!##"), nIndex);
		::Sleep(500);
		::ReleaseSemaphore(g_hSema, 1, NULL);
	}
}

int main()
{
	g_hSema = ::CreateSemaphore(NULL, 3, 3, NULL);

	UINT nThreadId = 0;
	HANDLE hThread = NULL;

	for (int i = 0; i < 10;++i)
	{
		hThread = (HANDLE)::_beginthreadex(
			NULL,
			0,
			ThreadSemaphore,
			(LPVOID)i,
			0,
			&nThreadId
		);
		::CloseHandle(hThread);
	}

	while (1)
	{
		system("cls");
		for (int i = 0; i < 10; ++i)
		{
			_putws(g_StringList[i]);

			::Sleep(1000);
		}
	}

	::CloseHandle(g_hSema);
}
