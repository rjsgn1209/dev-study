#include <vector>

using namespace std;

//bool BinarySearch(const vector<int>& nums, int target)
//{
//	// 구현
//	vector<int> vec = nums;
//
//	while (vec.size() != 1)
//	{
//		vector<int> vecA(
//			vec.begin(),
//			vec.begin() + (vec.size() / 2));
//
//		vector<int> vecB(
//			vec.begin() + (vec.size() / 2),
//			vec.end());
//
//		if (vecA.back() >= target)
//		{
//			vec = vecA;
//		}
//		else
//		{
//			vec = vecB;
//		}
//	}
//
//	return vec.front() == target;
//}

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

int UpperBound(const vector<int>& nums, int target)
{
	// target보다 큰 값이 처음 등장하는 index 반환

	// 그런 값이 없다면
	// nums.size() 반환

	int left = 0;
	int right = static_cast<int>(nums.size()) - 1;
	int answer = static_cast<int>(nums.size());

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (nums[mid] > target)
		{
			answer = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return answer;
}

bool HasPairSum(const vector<int>& nums, int target)
{
	// nums는 오름차순 정렬되어 있다고 가정

	int left = 0;
	int right = static_cast<int>(nums.size()) - 1;

	while (left < right)
	{
		int sum = nums[left] + nums[right];
		if (sum == target)
		{
			return true;
		}
		else if (sum < target)
		{
			left++;
		}
		else
		{
			right--;
		}
	}

	return false;
}

bool HasSubarraySum(const vector<int>& nums, int target)
{
	// 연속 부분 배열 합이 target이면 true
	// 없으면 false

	int left = 0;
	int sum = 0;

	while (left < nums.size())
	{
		for (int right = 0; right < nums.size(); ++right)
		{
			sum += nums[right];

			if (sum == target)
			{
				return true;
			}
			else if (sum > target)
			{
				sum = 0;
				left++;
				right = left;
			}
		}

	}

	return false;
}

int BinarySearch(
	const vector<int>& nums,
	int target)
{
	// 구현
	int left = 0;
	int right = static_cast<int>(nums.size()) - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (target == nums[mid])
		{
			return mid;
		}
		else if (target > nums[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return -1;
}

pair<int, int> FindPair(
	const vector<int>& nums,
	int target)
{
	// 구현
	int left = 0;
	int right = static_cast<int>(nums.size()) - 1;

	while (left < right)
	{
		int sum = nums[left] + nums[right];
		if (target == sum)
		{
			return pair<int, int>(left, right);
		}
		else if (target > sum)
		{
			left++;
		}
		else
		{
			right--;
		}
	}

	return pair<int, int>(-1, -1);
}

void binarySearchBasic()
{
	/*vector<int> nums = { 1, 2, 1, 3, 2 };
	int target = 5;
	bool res = HasSubarraySum(nums, target);*/

	/*vector<int> nums = { 1, 3, 5, 7, 9, 11 };
	int target = 1;
	int res = BinarySearch(nums, target);*/

	vector<int> nums = { 1, 2, 4, 7, 11, 15 };
	int target = 15;
	pair<int, int> res = FindPair(nums, target);
	}