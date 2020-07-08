#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
	string answer = "";

	//�տ��� ���� ū ���� ���ʷ� ã��
	int temp_idx = -1;//���� ū ���� �ε����� �����ϴ� ����
	for (int i = 0; i < number.size() - k; i++) {
		char temp = '\0';
		int idx;
		for (idx = temp_idx + 1; number.size() - idx >= number.size() - (k + i); idx++) {
			if (number[idx] > temp) {
				temp = number[idx];
				temp_idx = idx;
			}
		}
		answer += temp;
	}
	cout << answer << endl;

	return answer;
}

int main() {
	string number = "1231234";

	solution(number, 3);
}