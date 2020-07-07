#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string solution(vector<int> numbers) {
	string answer = "";

	vector <pair<int, string>> standard;
	vector <string> combi;

	/*
	89
	8
	앞자리가 서로 같은경우 뒷자리를 비교하는데 
	만약 비교하는 두 수의 자릿수가 서로 맞지 않는 경우
	자릿수가 더많은 수의 뒷자리와 자릿수가 적은 수의 앞자리를 
	비교
	889 < 898
	8과 89를 어떻게 비교하면 좋을까
	일단 서로 같은것을 찾는다.
	서로 같은것끼리 정렬을 한다. 
	처음과 끝 인덱스를 도출해서 안쪽 루프를 돌리면 된다.
	*/

	//맨 앞자리수를 이용한 1차 정렬
	for (int i = 0; i < numbers.size(); i++) {
		
		string temp_string = to_string(numbers[i]);
		
		int temp_int = temp_string[0] - '0';
		standard.push_back(make_pair(temp_int, temp_string));
	}
	sort(standard.begin(), standard.end());
		
	int idx = 0; //temp_string에서 문자 인덱스 
	int same = 0;
	for (int i = 0; i < standard.size(); ) {
		
		int same = 1;
		int prev = i; //같은 숫자들이 시작되는 인덱스
		while (prev + 1 < standard.size() && standard[prev].first == standard[prev + 1].first) {
			same++;
			prev++;
		}

		for (int idx = 0; idx < 5; idx++) {
			for (int j = i; j < i + same; j++) {
				if (standard[j].second[idx + 1])
					standard[j].first = standard[j].second[idx + 1] - '0';
			}
			sort(standard.begin() + i, standard.begin() + i + same);
		}
		i += same;
	}

	standard;

	return answer;
}

int main() {
	vector <int> numbers = { 89,19,15, 8 };
	solution(numbers);

}