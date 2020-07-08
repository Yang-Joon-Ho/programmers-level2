#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
	string answer = "";

	//앞에서 부터 큰 수를 차례로 찾음
	int temp_idx = -1;//가장 큰 수의 인덱스를 저장하는 변수
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