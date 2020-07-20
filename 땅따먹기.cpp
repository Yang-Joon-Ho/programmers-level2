#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
	int answer = 0;

	//가장 큰 수와 인덱스 구함.
	int max_idx = max_element(land[0].begin(), land[0].end()) - land[0].begin();
	int max = *max_element(land[0].begin(), land[0].end());

	answer = max;
	//가장 큰 수 구했으면 해당 수는 0으로 둠
	land[0][max_idx] = 0;
	int max_second_idx = max_element(land[0].begin(), land[0].end()) - land[0].begin();
	int max_second = *max_element(land[0].begin(), land[0].end());
	
	for (int i = 1; i < land.size(); i++) {
		for (int j = 0; j < land[i].size(); j++) {
			if (j != max_idx)
				land[i][j] += max;
			else {
				land[i - 1][max_idx] = 0;
				land[i][j] += *max_element(land[i-1].begin(), land[i-1].end());
			}
		}
		max_idx = max_element(land[i].begin(), land[i].end()) - land[i].begin();
		max = *max_element(land[i].begin(), land[i].end());
	}

	return max;
}
