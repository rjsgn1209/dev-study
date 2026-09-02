#include <iostream>
#include <vector>

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
}