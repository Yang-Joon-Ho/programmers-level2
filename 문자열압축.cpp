#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {

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
					new_str.back() += temp;
					i += size;
				}
				dup = 0;
			}
		}

		if (i < s.size()) {
			new_str.back() += s.substr(i);
		}
		rank.push_back(new_str.back().size());
	}

	sort(rank.begin(), rank.end());

	if(rank.size())
		return rank.front();
	else
		return 1; //입력 문자열 길이가 1인 경우 
}
