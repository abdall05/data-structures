#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Stack
{
private:
	std::vector<T> data;

public:
	void push(T val);
	bool isEmpty() const;
	T pop();
	T top() const;
};

template <typename T>
void Stack<T>::push(T val)
{
	data.push_back(val);
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return data.empty();
}

template <typename T>
T Stack<T>::pop()
{
	if (data.empty())
		throw std::runtime_error("Stack underflow");
	T val = data.back();
	data.pop_back();
	return val;
}

template <typename T>
T Stack<T>::top() const
{
	if (isEmpty())
		throw std::runtime_error("Stack empty");
	return data.back();
}

int main()
{
	Stack<int> stack;
	for (int i = 0; i < 100; i++)
		stack.push(i);
	stack.pop();
	int top = stack.top();
	int isEmpty = stack.isEmpty();
}