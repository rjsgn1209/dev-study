// CreateThread.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <windows.h>

DWORD WINAPI ThreadFunction(LPVOID pParam)
{
	std::cout << "ThreadFunction() - Begin" << std::endl;
	std::cout << (const char*)pParam << std::endl;
	std::cout << "ThreadFunction() - End" << std::endl;
	return 0;
}

int main()
{
	std::cout << "main() - Begin" << std::endl;
	DWORD dwThreadId = 0;
	HANDLE hThread = ::CreateThread(
		NULL,
		0,
		ThreadFunction,
		(LPVOID)"PARAM",
		0,
		&dwThreadId);
	if (hThread == NULL) {

	}

	std::cout << "main() - WaitForSingleObject() - before" << std::endl;

	::WaitForSingleObject(hThread, INFINITE);
	::CloseHandle(hThread);

	std::cout << "main() - End" << std::endl;
	return 0;
}