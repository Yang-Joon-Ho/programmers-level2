#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;

	vector <int> q; //q�� ����� 2
	sort(people.begin(), people.end());
	//�ִ��� ��Ʈ ���Կ� ������ ����� �¿��� �� 
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
			if (it == people.end()) { //�θ� �� �¿�� �ű�� ���� + Ÿ�� ����� �������� ���
				answer++; break;
			}
			weight = weight - q.front() + *it; //���� �ʱ�ȭ
			q.erase(q.begin());
			q.push_back(*it);
			it++;
		}
		else { //�θ� �� �¿�� �ű�� ���� 
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