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
		
		//3진수와 비교하면 1 = 1, 2 = 2, 10 = 4인 것이다. 
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
