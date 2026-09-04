
#include <iostream>
#include <deque>


class MyQueue
{
private:
    std::deque<int> data;

public:

    void Push(int value)
    {
        // 备泅
        data.push_back(value);
    }

    void Pop()
    {
        // 备泅
        data.pop_front();
    }

    int Front() const
    {
        // 备泅
        return data.front();
    }

    int Back() const
    {
        // 备泅
        return data.back();
    }

    bool Empty() const
    {
        // 备泅
        return data.empty();
    }

    size_t Size() const
    {
        // 备泅
        return data.size();
    }
};