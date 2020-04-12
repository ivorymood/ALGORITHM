//https://www.acmicpc.net/problem/10828
#pragma warning(disable: 4996)
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> stack;

	int count;
	cin >> count;

	while (count-- > 0) {
		string command;
		cin >> command;

		if (command == "push") {
			int num = 0;
			cin >> num;
			stack.push(num);

		} else if (command == "pop") {
			cout << (stack.empty() ? -1 : stack.top()) << '\n';
			
			if (!stack.empty()){
				stack.pop();
			}

		} else if (command == "size") {
			cout << stack.size() << '\n';

		} else if (command == "empty") {
			cout << stack.empty() << '\n';

		} else if (command == "top") {
			cout << (stack.empty() ? -1 : stack.top()) << '\n';
		
		}
	}

	return 0;
}