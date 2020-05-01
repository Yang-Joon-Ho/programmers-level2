#include <string>
#include <vector>

using namespace std;

string solution(int n) {
 string answer = "";

	while (n) {
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
