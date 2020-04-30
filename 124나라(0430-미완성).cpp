#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(int n) {
	string answer = "";

	unordered_map <int, char> temp;

	temp[1] = '2';
	temp[2] = '4';
	temp[4] = '1';
	/*41, 42, 44, 111, 112, 114, 121, 122, 124
	10을 3으로 나눈 몫 : 3, 나머지 : 1를 생각해보면
	10번 반복문 돌면서 */


	int i;
	int j;
	answer += '0';
	for (i = 3, j = 1; i <= n; i = ++j * 3) {
		//n이 6인 경우를 가정, 
		/*처음에 i가 3, 그리고 i = 6*/
		for (int j = answer.size() - 1; j >= 0; j--) {
			if (answer[answer.size() - 1] == '0') { //초기값
				answer[answer.size() - 1] = '4';
			}
			else if (j == 0 && answer[j] == '4') { //자릿수를 늘려야하는 경우
				answer[j] = temp[answer[j] - '0']; answer += '4';
			}
			else if (j != answer.size() - 1 && answer[j] == '4') { //자릿수가 넘어가는 경우
				answer[j] = temp[answer[j] - '0'];
			}
			else if(j != answer.size() - 1){ //그냥 증가시키는 경우
				answer[j] = temp[answer[j] - '0']; break;
			}
		}
	}

	for (i -= 3; i < n; i++) {
		for (int j = answer.size() - 1; j >= 0; j--) {
			if (j == 0 && answer[j] == '4') { //자릿수를 늘려야하는 경우
				answer[j] = temp[answer[j] - '0']; answer += '1';
			}
			else if (answer[j] == '4') { //자릿수가 넘어가는 경우
				answer[j] = temp[answer[j] - '0'];
			}
			else { //그냥 증가시키는 경우
				answer[j] = temp[answer[j] - '0']; break;
			}
		}
	}

	return answer;
}
