#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;

	priority_queue <int, vector <int>, less <int>> q;

	int j = 0; // dates를 위한 인덱스
	for (int i = 0; i < k; stock--, i++) {
		if (dates[j] == i) {
			if (j + 1 < supplies.size()) {
				q.push(supplies[j]);
				j++;
			}
		}
		if (stock == 0) {
			stock += q.top();
			q.pop();
			answer++;
		}
	}

	return answer;
}