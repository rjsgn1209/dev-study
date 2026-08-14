// ThreadEventWait.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
#include <process.h>
#include <windows.h>

UINT WINAPI ThreadFunction(LPVOID pParam)
{
    HANDLE hEvent = pParam;
    std::cout << "ThreadFunction() - Begin" << std::endl;

    _getch();
    SetEvent(hEvent);
    std::cout << "ThreadFunction() - SetEvent" << std::endl;
    std::cout << "ThreadFunction() - End" << std::endl;
    return 0;
}

int main()
{
    std::cout << "main() - Begin" << std::endl;
    HANDLE hEvent = ::CreateEvent(NULL, FALSE, FALSE, NULL);

    UINT nThreadId = 0;
    HANDLE hThread = (HANDLE)::_beginthreadex(
        NULL,
        0,
        ThreadFunction,
        (LPVOID)hEvent,
        0,
        &nThreadId
    );
    if (hThread == NULL) {
        std::cout << "ERROR: Failed to begin thread." << std::endl;
        return 0;
    }

    if (::WaitForSingleObject(
        hEvent, INFINITE) == WAIT_OBJECT_0)
    {
        std::cout << "main() - WaitForSingleObject() return" << std::endl;        
    }

    ::WaitForSingleObject(hThread, INFINITE);
    std::cout << "main() - Thread End" << std::endl;
    ::CloseHandle(hThread);
    std::cout << "main() - End" << std::endl;
}
