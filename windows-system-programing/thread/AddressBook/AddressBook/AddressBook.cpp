// AddressBook.cpp : LinkedList 형태의 주소록을 구현해보고 스레드를 활용한 대량 데이터를 파일로 저장하면서 주소록 기능도 정상적으로 동작할 수 있도록 코드 구현
//

#include <iostream>
#include <fstream>
#include <process.h>
#include <random>
#include <Windows.h>

typedef struct _LinkedAddress {
	int address;
	struct _LinkedAddress* next;
}LinkedAddress;

LinkedAddress* g_pLinkedAddress = NULL;
HANDLE g_hSaveEvent;
HANDLE g_hSaveThread;

LinkedAddress* make(int address)
{
	LinkedAddress* makeAddress = (LinkedAddress*)malloc(sizeof(LinkedAddress));
	makeAddress->address = address;
	makeAddress->next = NULL;
	return makeAddress;
}

LinkedAddress* findLastAddress()
{
	LinkedAddress* currAddress = g_pLinkedAddress;
	LinkedAddress* nextAddress = g_pLinkedAddress->next;
	while (true)
	{
		if (nextAddress == NULL)
		{
			break;
		}
		else
		{
			currAddress = currAddress->next;	// 현재 주소의 다음이 현재주소가 되고
			nextAddress = nextAddress->next;	// 다음 주소의 다음이 다음주소된다
		}
	}
	return currAddress;
}

void add(int address)
{
	if (g_pLinkedAddress == NULL)
	{
		g_pLinkedAddress = make(address);
	}
	else
	{
		LinkedAddress* lastAddress = findLastAddress();
		lastAddress->next = make(address);
	}
}

void remove(int address)
{
	bool bRemove = false;
	if (g_pLinkedAddress != NULL)
	{
		LinkedAddress* prevAddress = NULL;
		LinkedAddress* currAddress = g_pLinkedAddress;
		while (true)
		{
			if (currAddress == NULL)
			{
				break;
			}

			if (currAddress->address == address)
			{
				if (prevAddress == NULL)
				{
					g_pLinkedAddress = currAddress->next;
				}
				else
				{
					prevAddress->next = currAddress->next;
				}

				free(currAddress);
				bRemove = true;
				break;
			}

			prevAddress = currAddress;
			currAddress = currAddress->next;
		}
	}

	if (bRemove)
	{
		std::cout << address << " 주소를 삭제하였습니다." << std::endl;
	}
	else
	{
		std::cout << address << " 주소를 찾지못하였습니다." << std::endl;
	}
}

void printAll()
{
	if (g_pLinkedAddress != NULL)
	{
		LinkedAddress* currAddress = g_pLinkedAddress;
		while (true)
		{
			if (currAddress == NULL)
			{
				break;
			}

			std::cout << currAddress->address << std::endl;
			currAddress = currAddress->next;
		}
	}
}

void saveAll()
{
	if (g_pLinkedAddress != NULL)
	{
		std::ofstream file("address.txt");
		LinkedAddress* currAddress = g_pLinkedAddress;
		while (true)
		{
			if (currAddress == NULL)
			{
				break;
			}

			file << currAddress->address << std::endl;
			currAddress = currAddress->next;
		}
		file.close();
	}
}

unsigned int __stdcall saveThread(void* pParam)
{
	while (true)
	{
		// 저장 요청이 올 때까지 대기
		WaitForSingleObject(g_hSaveEvent, INFINITE);

		// 저장
		saveAll();
	}

	return 0;
}

int GetRandomNumber(int min, int max)
{
	static std::random_device rd;
	static std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dist(min, max);

	return dist(gen);
}

void createRandom(int count)
{
	LinkedAddress* lastAddress;
	if (g_pLinkedAddress == NULL)
	{
		g_pLinkedAddress = make(GetRandomNumber(0, 10000));
		lastAddress = g_pLinkedAddress;
	}
	else
	{
		lastAddress = findLastAddress();
	}

	for (int i = 0; i < count; i++)
	{
		lastAddress->next = make(GetRandomNumber(0, 10000));
		lastAddress = lastAddress->next;
	}
}

void removeAll()
{
	if (g_pLinkedAddress != NULL)
	{		
		LinkedAddress* currAddress = g_pLinkedAddress;
		LinkedAddress* nextAddress = g_pLinkedAddress->next;
		while (true)
		{
			free(currAddress);

			if (nextAddress == NULL)
			{
				g_pLinkedAddress = NULL;
				break;
			}

			currAddress = nextAddress;
			nextAddress = nextAddress->next;
		}
	}
}

int main()
{
	g_hSaveEvent = CreateEvent(
		nullptr,
		FALSE,
		FALSE,
		nullptr
	);

	g_hSaveThread = reinterpret_cast<HANDLE>(
		_beginthreadex(
			nullptr,
			0,
			saveThread,
			nullptr,
			0,
			nullptr
		)
		);

	std::cout << "주소록 서비스입니다." << std::endl;
	while (true)
	{
		int command = 0;
		std::cout << "(1.추가, 2.삭제, 3.전체조회, 4.저장, 5.랜덤 생성, 6.전체 삭제) : ";
		std::cin >> command;

		if (std::cin.fail())
		{
			std::cin.clear();              // fail 상태 초기화
			std::cin.ignore(1000, '\n');   // 입력 버퍼에서 잘못된 입력 제거

			std::cout << "숫자를 입력해주세요." << std::endl;
			continue;
		}

		switch (command)
		{
		case 1:
		{
			int address = 0;
			std::cout << "[추가] 추가할 주소를 입력해주세요: ";
			std::cin >> address;
			add(address);
			break;
		}

		case 2:
		{
			int address = 0;
			std::cout << "[삭제] 삭제할 주소를 입력해주세요: ";
			std::cin >> address;
			remove(address);
			break;
		}

		case 3:
			std::cout << "주소록 전체조회 내역입니다." << std::endl;
			printAll();
			break;

		case 4:
			std::cout << "주소록 전체를 파일로 저장합니다." << std::endl;
			SetEvent(g_hSaveEvent);			
			break;

		case 5:
		{
			int count = 0;
			std::cout << "랜덤 생성할 갯수를 입력하세요: ";
			std::cin >> count;
			createRandom(count);
			break;
		}

		case 6:
			removeAll();
			break;

		default:
			std::cout << "잘못된 명령어 입니다." << std::endl;
			break;
		}
	}
}
