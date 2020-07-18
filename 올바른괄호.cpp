#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
	bool answer = true;
	stack <char> stack;

	for (auto c : s) {
		if (c == '(')
			stack.push(c);
		else if (stack.size() == 0)
			return false;
		else
			stack.pop();
	}

	if (stack.size() > 0)
		return false;

	return answer;
}
