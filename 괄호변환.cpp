#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <string>

using namespace std;

string solution(string p) {
	
	if (p == "")
		return p;

	string answer = "";

	//u, v로 분할
	stack <char> stack;
	string u = "";
	string v = "";

	//u와 v를 나눔
	int i = 0;
	for (auto c : p) {
		// 스택.top()과 c가 다른 경우 u에는 추가하고 스택에서 뺀다.
		if (stack.size() && c != stack.top()) {
			stack.pop();
			u += c;
		}
		else if (u != "" && !stack.size()) { //u가 균형잡힌 괄호 ex) () or ))(( 인 경우
			v = p.substr(i);
			break;
		}	
		else {// 스택에 삽입하려는 괄호가 스택.top()과 같은 괄호인 경우 ex) "(("
			//혹은 아무것도 없는 경우
			stack.push(c);
			u += c;
		}
		i++;
	}

	//u가 올바른 문자열인지 확인해야함. 
	while (!stack.empty())stack.pop();
	// ()(()) 이런 경우라고 할 때
	for (i = 0; i < u.size(); i++) {
		if (u[i] == '(') {
			stack.push(u[i]);
		}//닫는 괄호 나와서 스택에서 여는 괄호 빼줘야 하는데 스택에 아무것도 없는 경우
		else if (u[i] == ')' && !stack.size()) {
			//균형잡힌 문자열 n의 처음과 마지막 인덱스를 없앰
			u.erase(u.begin());
			u.erase(u.end() - 1);
			//그리고 문자열 n의 모든 괄호를 뒤집는다. 
			for (int j = 0; j < u.size(); j++) {
				if (u[j] == '(')
					u[j] = ')';
				else
					u[j] = '(';

			}
			return answer = '(' + solution(v) + ')' + u;
		}
		else {
			stack.pop();
		}
	}

	//u가 올바른 문자열이라면 answer에 갖다 붙인다. 
	if (i == u.size())
		answer += u + solution(v);
	
	cout << answer << endl;

	return answer;
}

int main() {
	string p = ")()(";
	solution(p);
}