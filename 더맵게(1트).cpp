#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
	
	int answer = 0;
	/*
	int temp_size = scoville.size();
	for (int i = 0; i < scoville.size();) {
		//정렬
		sort(scoville.begin(), scoville.end());
		if (scoville[i] < K && i + 1 < scoville.size()) {
			//수치가 가장 낮은것 두개 조합
			scoville.push_back(scoville[i] + scoville[i + 1] * 2);
			//수치가 가장 낮은것과 그 다음것 삭제
			scoville.erase(scoville.begin());
			scoville.erase(scoville.begin());
			answer++;
		}
		else {
			break;
		}
	}

	if (scoville[scoville.size() - 1] < K)
		return -1;
	*/
	/*
	priority_queue <int, vector<int>, greater<int> > pq;
	for (int i = 0; i < scoville.size(); i++) {
		pq.push(scoville[i]);
	}

	while (pq.size()) {
		cout << pq.top() << endl;
		pq.pop();
	}
	*/
	/*
	if (K > scoville.size() * scoville.size() * *max_element(scoville.begin(), scoville.end()))
		return -1;
	*/

	while (scoville.size() > 1) {
		/*min_element()는 반복자 iter를 반환함, 따라서 iter가 가리키는 값을 
		받아오려면 *iter을 불러야 함.*/
		int min = *min_element(scoville.begin(), scoville.end());
		if (min >= K)
			break;
		scoville.erase(min_element(scoville.begin(), scoville.end()));

		//두번째로 작은 값 찾음
		int min_2nd = *min_element(scoville.begin(), scoville.end());
		scoville.erase(min_element(scoville.begin(), scoville.end()));

		scoville.push_back(min + min_2nd * 2);

		answer++;
	}

	if (scoville[scoville.size() - 1] < K)
		return -1;

	return answer;
}

int main() {

	vector <int> scoville = { 1,2,3,9,10,12 };

	solution(scoville, 7);
}