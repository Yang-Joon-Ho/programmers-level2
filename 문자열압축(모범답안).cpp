/*
원래 문제 의도보다 훨씬 더 복잡한 경우까지 고려하여 
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {

	int answer = 0;

	string temp; // 단위 길이로 자르는 용도
	vector <string> new_str;
	vector <int> rank;

	for (int size = 1; size <= s.size() / 2; size++) {

		new_str.push_back("");
		int dup = 0;
		int i;

		for (i = 0; i + size <= s.size();) {

			temp = s.substr(i, size);
			if (!temp.compare(s.substr(i + size, size)) && i < s.size()) {
				//같으면
				i += size;
				temp = s.substr(i, size);
				dup++;
			}
			else {
				//다르면
				if (dup) {
					new_str.back() += to_string(dup + 1) + temp;
					i += size;
				}
				else {
					new_str.back() += temp.front();
					i++;
				}
				dup = 0;
			}
		}

		if (i < s.size()) {
			new_str.back() += s.substr(i);
		}
		rank.push_back(new_str.back().size());
	}

	new_str;
	sort(rank.begin(), rank.end());

	cout << rank.front() << endl;

	return answer;
}

int main() {

	string s = "xababcdcdababcdcd";

	solution(s);
}
