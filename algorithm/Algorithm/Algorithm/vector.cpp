#include <iostream>
#include <vector>

using namespace std;

void RemoveValue(
    vector<int>& nums,
    int target)
{
    // 구현
    auto pos = std::find(nums.begin(), nums.end(), target);
    while (pos != nums.end())
    {
        nums.erase(pos);
        pos = std::find(nums.begin(), nums.end(), target);
    }
}

void InsertAfter(
    vector<int>& nums,
    int target,
    int value)
{
    // 구현
    auto pos = std::find(nums.begin(), nums.end(), target); 
    if (pos != nums.end())
    {
        nums.insert(pos + 1, value);
    }
}

vector<int> Slice(
    const vector<int>& nums,
    int start,
    int end)
{
    // start와 end 모두 포함
    return vector<int>(nums.begin() + start, nums.begin() + end + 1);
}

void vectorBasic()
{
    std::vector<int> vec;

    for (int i = 0; i < 20; ++i)
    {
        vec.push_back(i);

        std::cout
            << "size: " << vec.size()
            << ", capacity: " << vec.capacity()
            << '\n';

        std::cout
            << "ptr: " << &vec[0]
            << '\n';
    }

    vector<int> nums = { 1, 3, 2, 3, 4, 3 };

    RemoveValue(nums, 3);

    nums = { 10, 20, 30, 40 };

    InsertAfter(nums, 20, 99);

    nums = { 10, 20, 30, 40, 50, 60 };

    vector<int> res = Slice(nums, 1, 3);
}