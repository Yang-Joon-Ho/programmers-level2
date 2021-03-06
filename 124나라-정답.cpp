//문제 : https://programmers.co.kr/learn/courses/30/lessons/12899

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
 string answer = "";

	while (n) {
		// ex) 3의 경우 3 % 3 = 0, n = 3 / 3 - 1 = 0, n이 0이 되면 조건에 의해 반복문을 빠져나감
		// ex) 6의 경우 6 % 3 = 0, n = 6 / 3 - 1 = 1, 
		// ex) 9의 경우 9 % 3 = 0, n = 9 / 3 - 1 = 2
		// 3의 배수는 앞자리가 0, 1, 2가 반복된다는 사실을 알아야 한다. 
		// 그리고 가장 작은 자리 수는 4이다. 
		
		// 3진수와 비교하면 1 = 1, 2 = 2, 10 = 4인 것이다. 
		// 그리고 3 = 4, 6 = 14, 9 = 24인 것을 봤을 때,
		// 3은 3으로 나누어 떨어지므로 4,
		// 6은 3으로 나누어 떨어지므로 끝에 4가 오긴 하는데, 1은 어떻게 온건지 생각해봐야함
		// 6 / 3 = 2 - 1 = 1인가?
		// 다시 9를 봤을 떄, 9 / 3 = 3 - 1 = 2 
		// 위와 같은 과정을 통해 n % 3 = 0일 때, n = n / 3 - 1임을 알 수 있다. 
		
		// 그리고 문제 조건에서 "124나라에는 자연수만 존재한다." 라는 것을 보아, 0은 고려하지 않으므로
		// 3 = 4인것을 알 수 있다. 
		
		if (n % 3 == 0) {
			answer.insert(0, "4");
			n = n / 3 - 1;
		}
		else {
			answer.insert(0, to_string(n % 3));
			n = n / 3;
		}
	}
	
	//cout << answer << endl;

	return answer;
}
