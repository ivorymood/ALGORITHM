#include <iostream>

using namespace std;

struct Stack {
	int data[10000];
	int size;

	void push(int num)
	{
		data[size] = num;
		size++;
	}

	int pop()
	{
		if (empty())
		{
			return -1;
		}

		size--;
		return data[size];
	}

	bool empty()
	{
		return (size == 0);
	}

	int top()
	{
		if (empty())
		{
			return -1;
		}

		return data[size - 1];
	}
};

int main()
{
	int count;
	cin >> count;

	Stack stack{};

	while (count-- > 0) {
		string command;
		cin >> command;

		if (command == "push") {
			int num = 0;
			cin >> num;
			stack.push(num);

		} else if (command == "pop") {
			cout << stack.pop() << '\n';

		} else if (command == "size") {
			cout << stack.size << '\n';

		} else if (command == "empty") {
			cout << stack.empty() << '\n';

		} else if (command == "top") {
			cout << stack.top() << '\n';
		}
	}

	return 0;
}