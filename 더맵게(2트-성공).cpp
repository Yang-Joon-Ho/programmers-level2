#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
	
	int answer = 0;
	
	priority_queue <int, vector<int>, greater<int> > pq;
	for (int i = 0; i < scoville.size(); i++) {
		pq.push(scoville[i]);
	}

	while (pq.size() > 1) {
		int min = pq.top();
		if (min >= K)
			break;
		pq.pop();

		int min_2nd = pq.top();
		pq.pop();

		pq.push(min + min_2nd * 2);

		answer++;
	}

	if (pq.top() < K)
		return -1;

	return answer;
}

int main() {

	vector <int> scoville = { 1,2,3,9,10,12 };

	solution(scoville, 7);
}