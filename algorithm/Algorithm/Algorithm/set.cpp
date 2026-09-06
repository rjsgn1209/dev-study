
#include <vector>
#include <unordered_set>

using namespace std;

bool HasDuplicate(const vector<int>& numbers)
{
	// ±¸Çö    
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

void setBasic()
{
	vector<int> values = { 1,2,3,2,5 };

	bool res = HasDuplicate(values);
}