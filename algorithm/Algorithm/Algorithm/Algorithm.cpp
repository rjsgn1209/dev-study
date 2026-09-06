// Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include "vector.h"
#include "stack.h"
#include "map.h"
#include "set.h"
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>

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
//vector<int> solution(vector<int> arr, int divisor) {
//	vector<int> answer;
//
//	for (int var : arr)
//	{
//		int remain = var % divisor;
//		if (remain == 0)
//		{
//			answer.push_back(var);
//		}
//	}
//
//	if (answer.size() > 0)
//	{
//		sort(answer.begin(), answer.end());
//	}
//	else
//	{
//		answer.push_back(-1);
//	}
//
//	return answer;
//}

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

//// 가장 가까운 같은 글자
//int* solution(const char* s) {
//	int size = strlen(s);
//	int* answer = (int*)malloc(sizeof(int) * size);
//
//	for (int i = 0; i < size;i++)
//	{
//		int findDist = -1;
//		int calcDist = 0;
//
//		for (int j = i - 1; j >= 0; j--)
//		{
//			if (s[i] == s[j])
//			{
//				calcDist += 1;
//				findDist = calcDist;
//				break;
//			}
//			else
//			{
//				calcDist += 1;
//			}
//		}
//		answer[i] = findDist;
//	}
//
//	return answer;
//}
//
//struct Person
//{
//	std::string name;
//	int age;
//	int score;
//};
//
//vector<Person> sortPerson(vector<Person> vec)
//{
//	sort(vec.begin(), vec.end(),
//		[](const Person& a, const Person& b)
//		{
//			if (a.age == b.age)
//			{
//				return a.score > b.score;
//			}
//
//			return a.age < b.age;
//		});
//
//	return vec;
//}

// 올바른 괄호
//bool solution(string s) {
//	stack<char> stack;
//
//	for (int i = 0; i < s.size();i++)
//	{
//		if (s[i] == '(')
//		{
//			stack.push(s[i]);
//		}		
//		else if(s[i] == ')')
//		{
//			if (stack.empty())
//			{
//				stack.push(s[i]);
//				break;
//			}
//			else
//			{
//				stack.pop();
//			}
//		}
//	}
//
//	return stack.empty();
//}

// 기능개발
//vector<int> solution(vector<int> progresses, vector<int> speeds) {
//	vector<int> answer;
//	deque<int> progDeque;
//	deque<int> spdDeque;
//	int cnt = 0;
//
//	for (int i = 0; i < progresses.size(); i++)
//	{
//		progDeque.push_back(progresses[i]);
//		spdDeque.push_back(speeds[i]);
//	}
//
//	while (!progDeque.empty())
//	{
//		int size = progDeque.size();
//		for (int i = 0; i < size; i++)
//		{
//			progDeque[i] += spdDeque[i];
//		}
//
//		for (int i = 0; i < size; i++)
//		{
//			if (progDeque.front() > 100)
//			{
//				cnt += 1;
//				progDeque.pop_front();
//				spdDeque.pop_front();
//			}
//			else
//			{
//				break;
//			}
//		}
//
//		if (cnt != 0)
//		{
//			answer.push_back(cnt);
//			cnt = 0;
//		}
//	}
//
//
//	return answer;
//}

// 프로세스
//int solution(vector<int> priorities, int location) {
//	queue<int> que;
//
//	for (int i = 0; i < priorities.size();i++)
//	{
//		que.push(i);
//	}
//
//	bool excute = false;
//	int cycle = 0;
//	int currentIndex = -1;
//	while (!que.empty())
//	{
//		currentIndex = que.front();
//		que.pop();
//		excute = true;
//
//		for (int i = 0; i < priorities.size();i++)
//		{
//			if (priorities[currentIndex] < priorities[i])
//			{
//				que.push(currentIndex);
//				excute = false;
//				break;
//			}
//		}
//
//		if (excute)
//		{
//			cycle += 1;
//
//			priorities[currentIndex] = 0;
//
//			if (currentIndex == location)
//			{
//				break;
//			}
//		}
//	}
//
//	return cycle;
//}

// 폰켓몬
//int solution(vector<int> nums)
//{
//	int count = nums.size() / 2;
//	unordered_set<int> unorderedSet;
//
//	for (const int var : nums)
//	{
//		unorderedSet.insert(var);
//	}
//
//	return unorderedSet.size() > count ? count : unorderedSet.size();
//}

// 완주하지 못한 선수
//string solution(vector<string> participant, vector<string> completion) {
//	string answer = "";
//	unordered_map<string, int> participantMap;
//	unordered_map<string, int> completionMap;
//
//	for (string var : participant)
//	{
//		participantMap[var]++;
//	}
//
//	for (string var : completion)
//	{
//		completionMap[var]++;
//	}
//
//	for (const auto& var : participantMap)
//	{
//		if (var.second != completionMap[var.first])
//		{
//			return var.first;
//		}
//	}
//
//	return answer;
//}

// 의상
//int solution(vector<vector<string>> clothes) {
//	int answer = 1;
//	unordered_map<string, vector<string>> map;
//	unordered_set<string> keys;
//
//	for (const auto& vec : clothes)
//	{
//		map[vec[1]].push_back(vec[0]);
//		keys.insert(vec[1]);
//	}
//	
//	for (const string& var : keys)
//	{
//		answer *= map[var].size() + 1;		
//	}
//
//
//	return answer - 1;
//}

// 전화번호 목록
//bool solution(vector<string> phone_book) {
//	bool answer = true;
//	unordered_set<string> set;
//	vector<string> vec;
//	vec.resize(phone_book.size());
//	int maxSize = 0;
//
//	// 1번 방법
//	for (int i = 0; i < phone_book.size(); i++)
//	{
//		if (maxSize < phone_book[i].size())
//		{
//			maxSize = phone_book[i].size();
//		}
//	}
//
//	
//	for (int index = 0; index < maxSize; index++)
//	{
//		bool findCompletion = false;
//		for (int i = 0; i < phone_book.size(); i++)
//		{
//			if (index < phone_book[i].size())
//			{
//				char c = phone_book[i][index];
//				vec[i].push_back(c);
//				if (vec[i].size() == phone_book[i].size())
//				{
//					findCompletion = true;
//				}
//			}
//		}
//
//		if (findCompletion)
//		{
//			set.clear();
//			for (const string& var : vec)
//			{
//				if (!set.insert(var).second)
//				{
//					return false;
//				}
//			}
//		}
//	}
//	
//	// 2번 방법
//	/*for (int i = 0; i < phone_book.size() - 1; i++)
//	{
//		for (int j = i + 1; j < phone_book.size(); j++)
//		{
//			if (phone_book[i].size() <= phone_book[j].size())
//			{
//				string sub = phone_book[j].substr(0, phone_book[i].size());
//				if (phone_book[i] == sub)
//				{
//					return false;
//				}
//			}
//		}
//	}*/
//
//	return answer;
//}

void Func()
{
	std::unique_ptr<int> ptr = std::make_unique<int>();
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
	//mystackFunction();

	// 기능개발
	/*vector<int> progressse = { 95,90,99,99,80,99 };
	vector<int> speeds = { 1,1,1,1,1,1 };
	vector<int> res = solution(progressse, speeds);*/

	// 프로세스
	/*vector<int> priorities = { 2,1,3,2 };
	int location = 2;
	int res = solution(priorities, location);*/

	//mapBasic();
	//setBasic();

	// 폰켓몬
	/*vector<int> nums = { 3,3,3,2,2,2 };
	int res = solution(nums);*/

	// 완주하지 못한 선수
	/*vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
	vector<string> completion = { "stanko", "ana", "mislav" };
	string res = solution(participant, completion);*/

	// 의상
	/*vector<vector<string>> clothes = { { "yellow_hat", "headgear" }, { "blue_sunglasses", "eyewear" }, { "green_turban", "headgear" } };
	int res = solution(clothes);*/

	// 전화번호 목록
	vector<string> vec = { "12","123","1235","567","88" };
	bool res = solution(vec);
}
