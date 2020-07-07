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

	//u, v�� ����
	stack <char> stack;
	string u = "";
	string v = "";

	//u�� v�� ����
	int i = 0;
	for (auto c : p) {
		// ����.top()�� c�� �ٸ� ��� u���� �߰��ϰ� ���ÿ��� ����.
		if (stack.size() && c != stack.top()) {
			stack.pop();
			u += c;
		}
		else if (u != "" && !stack.size()) { //u�� �������� ��ȣ ex) () or ))(( �� ���
			v = p.substr(i);
			break;
		}	
		else {// ���ÿ� �����Ϸ��� ��ȣ�� ����.top()�� ���� ��ȣ�� ��� ex) "(("
			//Ȥ�� �ƹ��͵� ���� ���
			stack.push(c);
			u += c;
		}
		i++;
	}

	//u�� �ùٸ� ���ڿ����� Ȯ���ؾ���. 
	while (!stack.empty())stack.pop();
	// ()(()) �̷� ����� �� ��
	for (i = 0; i < u.size(); i++) {
		if (u[i] == '(') {
			stack.push(u[i]);
		}//�ݴ� ��ȣ ���ͼ� ���ÿ��� ���� ��ȣ ����� �ϴµ� ���ÿ� �ƹ��͵� ���� ���
		else if (u[i] == ')' && !stack.size()) {
			//�������� ���ڿ� n�� ó���� ������ �ε����� ����
			u.erase(u.begin());
			u.erase(u.end() - 1);
			//�׸��� ���ڿ� n�� ��� ��ȣ�� �����´�. 
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

	//u�� �ùٸ� ���ڿ��̶�� answer�� ���� ���δ�. 
	if (i == u.size())
		answer += u + solution(v);
	
	cout << answer << endl;

	return answer;
}

int main() {
	string p = ")()(";
	solution(p);
}