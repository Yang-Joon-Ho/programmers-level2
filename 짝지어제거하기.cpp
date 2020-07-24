#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
	
	stack <char> stack;
	stack.push(s.front());

	for (string::iterator it = s.begin() + 1; it != s.end(); it++) {
		if (stack.size() && stack.top() == *it)
			stack.pop();
		else
			stack.push(*it);
	}
	
	if (stack.size())
		return 0;
	else
		return 1;
}
