// Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include "vector.h"
#include "stack.h"

using namespace std;

void pointerFunction()
{
	int value = 10;

	int* ptr = &value;
	int& ref = value;

	std::cout << value << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;

	*ptr = 20;

	std::cout << value << std::endl;

	ref = 30;

	std::cout << value << std::endl;
}

void constFunction()
{
	int value1 = 10;
	int value2 = 20;
	int* pOrg = &value1;
	int* pOrg2 = &value2;

	const int* p = pOrg;
	int* const p2 = pOrg;
	const int* const p3 = pOrg;

	// *p = 20;		안됨
	p = pOrg2;

	// p2 = pOrg2;	안됨
	*p2 = 20;

	// p3 = pOrg2;	안됨
	// *p3 = 20;	안됨
}

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int Sum(const std::vector<int>& vec)
{
	int res = 0;
	for (const int var : vec)
	{
		res += var;
	}
	return res;
}

int FindMax(int* arr, int size)
{
	int maxValue = 0;
	for (int i = 0; i < size; i++)
	{
		if (maxValue < arr[i])
		{
			maxValue = arr[i];
		}
	}
	return maxValue;
}

// 최댓값과 최솟값
string MaxAndMinValue(string s)
{
	int findIndex = 0;
	int startIndex = 0;
	std::vector<int> vec;
	findIndex = s.find(' ');
	while (findIndex != string::npos)
	{
		string subString = s.substr(startIndex, findIndex - startIndex);
		vec.push_back(std::stoi(subString));
		startIndex = findIndex + 1;
		findIndex = s.find(' ', startIndex);
	}
	int size = s.size();
	vec.push_back(std::stoi(s.substr(startIndex, size - startIndex)));

	int minValue = INT_MAX;
	int maxValue = INT_MIN;
	for (int var : vec)
	{
		if (minValue > var)
		{
			minValue = var;
		}

		if (maxValue < var)
		{
			maxValue = var;
		}
	}

	return std::to_string(minValue) + " " + std::to_string(maxValue);
}

// 문자열 내 마음대로 정렬하기
vector<string> stringIndexSort(vector<string> strings, int n) {
	vector<string> answer;

	std::sort(strings.begin(), strings.end(),
		[n](const string& a, const string& b)
		{
			if (a[n] == b[n])
			{
				return a < b;
			}

			return a[n] < b[n];
		});

	return strings;
}

// 같은 숫자는 싫어
//vector<int> solution(vector<int> arr)
//{
//	vector<int> answer;
//
//	int prev = -1;
//	for (int var : arr)
//	{
//		if (prev != var)
//		{
//			answer.push_back(var);
//			prev = var;
//		}
//	}
//
//	return answer;
//}

// 문자열 내 p와 y의 개수
//bool solution(string s)
//{
//	bool answer = true;
//
//	int pCnt = 0;
//	int yCnt = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		char c = s[i];
//		if (c == 'p' || c == 'P')
//		{
//			pCnt += 1;
//		}
//
//		if (c == 'y' || c == 'Y')
//		{
//			yCnt += 1;
//		}
//	}
//
//	if (pCnt != yCnt)
//	{
//		answer = false;
//	}
//
//	return answer;
//}

// 나누어 떨어지는 숫자배열
vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;

	for (int var : arr)
	{
		int remain = var % divisor;
		if (remain == 0)
		{
			answer.push_back(var);
		}
	}

	if (answer.size() > 0)
	{
		sort(answer.begin(), answer.end());
	}
	else
	{
		answer.push_back(-1);
	}

	return answer;
}

// K번째수
//vector<int> solution(vector<int> array, vector<vector<int>> commands) {
//	vector<int> answer;
//	for (vector<int> vec : commands)
//	{
//		int startIndex = vec[0] - 1;
//		int endIndex = vec[1];
//		int findIndex = vec[2] - 1;
//
//		vector<int> sub(array.begin() + startIndex, array.begin() + endIndex);
//		sort(sub.begin(), sub.end());
//		answer.push_back(sub[findIndex]);
//	}
//
//	return answer;
//}

// 가장 가까운 같은 글자
int* solution(const char* s) {
	int size = strlen(s);
	int* answer = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size;i++)
	{
		int findDist = -1;
		int calcDist = 0;

		for (int j = i - 1; j >= 0; j--)
		{
			if (s[i] == s[j])
			{
				calcDist += 1;
				findDist = calcDist;
				break;
			}
			else
			{
				calcDist += 1;
			}
		}
		answer[i] = findDist;
	}

	return answer;
}

struct Person
{
	std::string name;
	int age;
	int score;
};

vector<Person> sortPerson(vector<Person> vec)
{
	sort(vec.begin(), vec.end(),
		[](const Person& a, const Person& b)
		{
			if (a.age == b.age)
			{
				return a.score > b.score;
			}

			return a.age < b.age;
		});

	return vec;
}

int main()
{
	//pointerFunction();
	//constFunction();

	//int a = 10, b = 20;
	//Swap(a, b);
	//std::cout << a << " " << b << std::endl;

	/*std::vector<int> vec = { 10, 20, 30, 40 };
	int sumValue = Sum(vec);
	std::cout << sumValue << std::endl;*/

	/*int arr[5] = { 1, 5, 3, 7, 2 };
	int maxValue = FindMax(arr, 5);
	std::cout << maxValue << std::endl;*/

	// 최댓값과 최솟값
	/*string str = "-1 -2 -3 -4";
	string minMaxString = "";
	minMaxString = MaxAndMinValue(str);*/

	// 문자열 내 마음대로 정렬하기
	/*vector<string> stringVec = { "sun", "bed", "car" };
	vector<string> result = stringIndexSort(stringVec, 1);*/

	// 문자열 내 p와 y의 개수
	/*vector<int> vec = { 1,1,3,3,0,0,1,1 };
	vector<int> res = solution(vec);*/

	// 문자열 내 p와 y의 개수
	//string input = "pPoooyY";
	//string input2 = "Pyy";
	//bool res = solution(input2);

	//vectorBasic();

	// 나누어 떨어지는 숫자배열
	//vector<int> arr = { 5,9,7,10 };
	//vector<int> arr = { 2,36,1,3 };
	/*vector<int> arr = { 3, 2, 6 };
	int divisor = 10;
	vector<int> res = solution(arr, divisor);*/

	// K번째수
	/*vector<int> array = { 1,5,2,6,3,7,4 };
	vector<vector<int>> commands = { {2,5,3},{4,4,1},{1,7,3} };
	vector<int> res = solution(array, commands);*/

	/*const char* s = "foobar";
	int* res = solution(s);

	for (int i = 0; i < strlen(s); i++)
	{
		std::cout << res[i] << "\n";
	}*/

	/*vector<Person> vec {
		{"Kim", 30, 80},
		{"Lee", 25, 90},
		{"Park", 25, 70},
		{"Choi", 30, 95}
	};
	vector<Person> res = sortPerson(vec);*/

	//stackBasic();
	mystackFunction();
}
