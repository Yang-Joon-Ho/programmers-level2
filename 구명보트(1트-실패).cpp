#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;

	vector <int> q; //q는 사이즈가 2
	sort(people.begin(), people.end());
	//최대한 보트 무게에 가깝게 사람을 태워야 함 
	int weight = 0;
	for (vector <int>::iterator it = people.begin(); it != people.end(); ) {
		if (q.size() < 2) {
			if (weight + *it <= limit) {
				weight += *it;
				q.push_back(*it);
				it++;
			}
			else {
				q.clear();
				weight = *it;
				q.push_back(*it);
				it = people.erase(it - 1);
				answer++;
			}
		}
		else if((weight - q.front() + *it) <= limit && limit - (weight - q.front() + *it) <= limit - weight) {
			if (it == people.end()) { //두명 다 태우고 옮기는 상태 + 타는 사람이 마지막인 경우
				answer++; break;
			}
			weight = weight - q.front() + *it; //무게 초기화
			q.erase(q.begin());
			q.push_back(*it);
			it++;
		}
		else { //두명 다 태우고 옮기는 상태 
			people.erase(it - q.size(), it);
			q.clear();
			it = people.begin();
			answer++;
			weight = 0;
		}
	}

	return answer;
}


int main() {

	vector <int> people = { 70, 50, 80, 50 };
	int limit = 100;

	//vector <int> people = { 70 };
	//int limit = 100;

	solution(people, limit);
}