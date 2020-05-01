#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
vector<int> answer;

	int prev = 0; // 작업 완료되기 까지의 기간(일) 
	int pre = 0;
	for (int i = 0; i < speeds.size(); i++) { 

		if((100 - progresses[i]) % speeds[i] == 0)
			pre = (100 - progresses[i]) / speeds[i];
		else
			pre = (100 - progresses[i]) / speeds[i] + 1;

		if (pre <= prev)
			answer.back()++;
		else {
			prev = pre;
			answer.push_back(1);
		}
	}
	//100 - 93 = 7 / 1이 작업을 완료하는데 걸리는 시간


	return answer;
}
