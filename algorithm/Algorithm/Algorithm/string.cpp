
#include <vector>
#include <string>

using namespace std;

vector<string> Split(
	const string& str,
	char delimiter)
{
	// ±¸Çö

	vector<string> vec;
	int start = 0;
	int find = static_cast<int>(str.find(delimiter, start));

	while (find != string::npos)
	{
		string str2 = str.substr(start, find - start);
		vec.push_back(str2);
		start = find + 1;
		find = static_cast<int>(str.find(delimiter, start));
		if (find == static_cast<int>(string::npos))
		{
			vec.push_back(str.substr(start));
			break;
		}
	}

	return vec;
}

void stringBasic()
{
	vector<string> res = Split("apple,banana,orange", ',');
}