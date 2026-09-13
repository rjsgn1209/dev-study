
#include <map>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

unordered_map<string, int> CountFruits(
	const vector<string>& fruits)
{
	unordered_map<string, int> ret;
	// 流立 备泅
	for (string var : fruits)
	{
		ret[var] += 1;
	}

	return ret;
}

unordered_map<string, int> CountWords(
	const vector<string>& words)
{
	// 备泅
	unordered_map<string, int> m;

	for (const string& var : words)
	{
		m[var]++;
	}
	return m;
}

bool HasCommonKey(
	const unordered_map<string, int>& a,
	const unordered_map<string, int>& b)
{
	// 备泅
	for (const auto& var : a)
	{
		if (b.find(var.first) != b.end())
		{
			return true;
		}
	}

	return false;
}

void mapBasic()
{
	/*vector<string> fruits =
	{
		"apple",
		"banana",
		"apple",
		"orange",
		"banana",
		"apple"
	};

	unordered_map<string, int> res = CountFruits(fruits);*/

	/*vector<string> words = { "apple", "banana", "apple", "orange", "banana", "apple" };
	unordered_map<string, int> res = CountWords(words);*/

	const unordered_map<string, int>& a = {
	{"apple", 3},
	{"banana", 2}
	};

	const unordered_map<string, int>& b = {
		{"orange", 5},
		{"banana", 10}
	};
	bool res = HasCommonKey(a, b);
}