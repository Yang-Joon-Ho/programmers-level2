#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include <unordered_map>
#include <string>

using namespace std;
int map[8] = { 0,1,2,3,4,5,6,7 };

vector <vector<int>> nCr_with_next_permutation(int n, int r) {

	vector<int> mask;

	// 1. mask 벡터를 n개만큼 push 합니다.
	// 2. 내가 뽑고자 하는 r개에는 0을 push.
	//    아닌 경우는 1을 push 합니다.
	for (int i = 0; i < n; i++) {
		if (i < r) {
			mask.push_back(0);
		}
		else mask.push_back(1);
	}

	// 3. mask 벡터를 sort 시킵니다.
	// sort는 <algorithm>에 정의되어 있습니다.
	sort(mask.begin(), mask.end());

	vector <vector <int>> temp_v;
	// O(nCr*n)의 시간이 걸립니다. 
	while (1) {
		vector <int> temp;
		// 4. n까지 순회하며 mask가 0인 i만 map에서 출력하면 됩니다.
		// map 자체는 변하지 않고, mask가 일종의 비트마스크의 마스크같은 개념과 비슷합니다.
		for (int i = 0; i < n; i++) {
			if (mask[i] == 0) {
				temp.push_back(map[i]);
			}
		}
		temp_v.push_back(temp);
		if (!next_permutation(mask.begin(), mask.end())) break;
	}
	return temp_v;
}

int solution(vector<vector<string>> relation) {

	int answer = 0;

	unordered_map <string, int> jungbook;

	for (int i = 1; i <= relation.size(); i++) {
		vector<vector<int>> combi;
		combi = nCr_with_next_permutation(relation[0].size(), i);

		for (auto c : combi) {
			unordered_map <string, int> map;
			for (int j = 0; j < relation.size(); j++) {
				string temp_s;
				for (auto k : c) { // ex) 0열 3열 
					temp_s += relation[j][k];
				}
				map[temp_s]++;
			}

			bool count = true;
			for (auto pair : map) {
				if (pair.second > 1) {
					count = false;
					break;
				}
			}

			if (count) {

				string temp_c;
				for (auto k : c)
					temp_c += to_string(k);

				if (!jungbook.size()) jungbook[temp_c]++;

				else {
					bool judge = true;

					for (auto pair : jungbook) {
						int j;
						string temp = pair.first;
						for (j = 0; j < temp_c.size(); j++) {
							
							if (find(temp.begin(), temp.end(), temp_c[j]) < temp.end()) {
								temp.erase(find(temp.begin(), temp.end(), temp_c[j]));
							}
						}

						if (!temp.size()) {
							judge = false; break;
						}
					}
					if (judge) jungbook[temp_c]++;
				}
			}
		}
	}
		
	return jungbook.size();
}

int main() {
	vector<vector<string>> relation = { { "b","2","a","a","b" },
	{ "b","2","7","1","b" },
	{ "1","0","a","a","8" },
	{ "7","5","a","a","9" },
	{ "3","0","a","f","9" }, };
	solution(relation);
}
