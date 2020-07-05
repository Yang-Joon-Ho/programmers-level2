#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int SIZE = 26;

int solution(string name) {
	int answer = 0;

	//알파벳 정방향, 역방향 이동 횟수 저장하는 벡터
	vector <pair <int, int>> alpha;
	//좌우로 움직인 거리
	vector <int> distance;

	//알파벳 조작
	for (int i = 0; i < name.size(); i++) {
		if (name[i] != 'A')
			alpha.push_back(make_pair(name[i] - 'A', SIZE - (name[i] - 'A')));
	}

	int Acount = 0;
	int count = -1;
	//정방향
	for (int i = 0; i < name.size(); i++) {
		if (Acount > 0 && name[i] != 'A') {
			Acount = 0;
		}
		else if (i + 1 == name.size() && name[i] == 'A') {
			count -= Acount;
			break;
		}
		else if (name[i] == 'A') {
			Acount++;
		}
		
		//이동거리 증가시킴
		count++;
	}
	if (count < 0)
		count = 0;

	distance.push_back(count);
	
	
	//역방향
	count = -1; // count는 이동거리
	Acount = 0; // 연속되는 A의 개수
	int reverse_idx = -1; // 역방향으로 방향을 튼 시점의 인덱스
	for (int i = 0; i < name.size();) {
		
		//역방향으로 가다가 역방향으로 튼 순간의 인덱스를 만났을 때, 즉 끝났을 때
		if (name.size() - (i+1) == reverse_idx) {
			count -= Acount;
			break;
		}
		//역방향으로 가는 도중 A를 만났다가 계속 가는데 A가 아닌 다른 알파벳이 나온 경우
		else if (reverse_idx != -1 && Acount > 0 && name.size() - (i + 1) >= 0 && name[name.size() - (i + 1)] != 'A') {
			Acount = 0;
		}
		//역방향으로 가는 도중 A를 만났을 때 
		else if (reverse_idx != -1 && name.size() - (i + 1) >= 0 && name[name.size() - (i + 1)] == 'A') {
			Acount++;
		}
		else if (reverse_idx == -1 && name[i] == 'A') {
			reverse_idx = i;
			if (count == -1)
				count = 0;
			else {
				count += count; //오른쪽 끝으로 옮긴다
			}
			i = 0; //인덱스는 0으로 초기화
			continue;
		}
		i++;
		count++;
	}
	distance.push_back(count);

	//역방향으로 가는데 A가 두개 이상 붙어있는 경우에만 역으로 가는 경우
	int i = 0;
	reverse_idx = -1;
	count = -1;
	while (1) {
		//역방향으로 가다가 역방향으로 튼 순간의 인덱스를 만났을 때, 즉 끝났을 때
		if (name.size() - (i + 1) == reverse_idx) {
			count -= Acount;
			break;
		}
		//역방향으로 가는 도중 A를 만났다가 계속 가는데 A가 아닌 다른 알파벳이 나온 경우
		else if (reverse_idx != -1 && Acount > 0 && name.size() - (i + 1) >= 0 && name[name.size() - (i + 1)] != 'A') {
			Acount = 0;
		}
		//역방향으로 가는 도중 A를 만났을 때 
		else if (reverse_idx != -1 && name.size() - (i + 1) >= 0 && name[name.size() - (i + 1)] == 'A') {
			Acount++;
		}
		else if (name[i] == 'A' && i + 1 < name.size() && name[i + 1] == 'A') {
			reverse_idx = i;
			if (count == -1)
				count = 0;
			else {
				count += count; //오른쪽 끝으로 옮긴다
			}
			i = 0; //인덱스는 0으로 초기화
			continue;
		}
		i++;
		count++;
	}
	distance.push_back(count);

	vector <int> sum;
	for (int i = 0; i < alpha.size(); i++) {
		sum.push_back(alpha[i].first < alpha[i].second ? alpha[i].first : alpha[i].second);
	}
	sort(distance.begin(), distance.end());
	sum.push_back(distance[0]);

	for (int i = 0; i < sum.size(); i++)
		answer += sum[i];



	for (int i = 0; i < distance.size(); i++)
		cout << distance[i] << endl;

	cout << answer << endl;



	return answer;
}

int main() {
	
	string name = "CANAAAAANAN";

	solution(name);
}