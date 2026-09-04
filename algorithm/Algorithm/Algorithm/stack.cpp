
#include <iostream>
#include <stack>
#include <vector>

void stackBasic()
{
	std::stack<int> stack;
	
	stack.push(10);
	stack.push(20);
	stack.push(30);

	std::cout << stack.top() << '\n';

	stack.pop();

	std::cout << stack.top() << '\n';

	std::cout << stack.size() << '\n';
}


class MyStack
{
private:
    std::vector<int> data;

public:

    void Push(int value)
    {
        // 流立 备泅
        data.push_back(value);
    }

    void Pop()
    {
        // 流立 备泅
        data.pop_back();
    }

    int Top() const
    {
        // 流立 备泅
        return data.back();
    }

    bool Empty() const
    {
        // 流立 备泅
        return data.empty();
    }

    size_t Size() const
    {
        // 流立 备泅
        return data.size();
    }
};

void mystackFunction()
{
    MyStack mystack;

    mystack.Push(10);
    mystack.Push(20);
    mystack.Push(30);

    std::cout << mystack.Top() << '\n';

    mystack.Pop();

    std::cout << mystack.Top() << '\n';

    std::cout << mystack.Size() << '\n';
}
