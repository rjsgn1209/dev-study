#include <vector>

using namespace std;

bool BinarySearch(const vector<int>& nums, int target)
{
	// 구현
	vector<int> vec = nums;

	while (vec.size() != 1)
	{
		vector<int> vecA(
			vec.begin(),
			vec.begin() + (vec.size() / 2));

		vector<int> vecB(
			vec.begin() + (vec.size() / 2),
			vec.end());

		if (vecA.back() >= target)
		{
			vec = vecA;
		}
		else
		{
			vec = vecB;
		}
	}

	return vec.front() == target;
}

int BinarySearchIndex(const vector<int>& nums, int target)
{
	// target을 찾으면 index 반환
	// 없으면 -1 반환

	int left = 0;
	int right = nums.size() - 1;
	bool lastCycle = false;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (nums[mid] == target)
		{
			return nums[mid];
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else if (nums[mid] > target)
		{
			right = mid - 1;
		}
	}
	return -1;
}

int LowerBound(const vector<int>& nums, int target)
{
	// target 이상의 값이 처음 등장하는 index 반환

	// 모든 값이 target보다 작으면
	// nums.size() 반환

	int left = 0;
	int right = nums.size() - 1;
	bool lastCycle = false;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (nums[mid] == target)
		{
			while (true)
			{
				if (mid > 0)
				{
					if (nums[mid - 1] == target)
					{
						mid -= 1;
					}
					else
					{
						return nums[mid];
					}
				}
			}
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else if (nums[mid] > target)
		{
			right = mid - 1;
		}
	}
	return -1;
}

void binarySearchBasic()
{
	vector<int> nums = { 1,3,3,3,5,7,9 };
	int target = 3;
	bool res = LowerBound(nums, target);
}