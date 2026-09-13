
#include <vector>
#include <unordered_set>

using namespace std;

bool HasDuplicate(const vector<int>& numbers)
{
	// 구현    
	unordered_set<int> unorderSet;

	for (int var : numbers)
	{
		if (unorderSet.find(var) == unorderSet.end())
		{
			unorderSet.insert(var);
		}
		else
		{
			return true;
		}
	}

	return false;
}

vector<int> FindCommon(
	const vector<int>& a,
	const vector<int>& b)
{
	// 구현
	unordered_set<int> s;
	vector<int> vec;

	for (int var : a)
	{
		s.insert(var);
	}

	for (int var : b)
	{
		if (s.find(var) != s.end())
		{
			vec.push_back(var);
		}
	}

	return vec;
}

void setBasic()
{
	/*vector<int> values = { 1,2,3,2,5 };

	bool res = HasDuplicate(values);*/

	const vector<int>& a = { 1, 2, 3, 4, 5 };
	const vector<int>& b = { 3, 4, 5, 6, 7 };
	vector<int> res = FindCommon(a, b);
}