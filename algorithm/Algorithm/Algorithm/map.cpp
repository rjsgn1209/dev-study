
#include <map>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

unordered_map<string, int> CountFruits(
	const vector<string>& fruits)
{
	unordered_map<string, int> ret;
	// 직접 구현
	for (string var : fruits)
	{
		ret[var] += 1;
	}

	return ret;
}

void mapBasic()
{
	vector<string> fruits =
	{
		"apple",
		"banana",
		"apple",
		"orange",
		"banana",
		"apple"
	};

	unordered_map<string, int> res = CountFruits(fruits);
}