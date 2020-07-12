#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

void print(vector <string> result, int *answer) {
	
	*answer += 1;
	
	for (int i = 0; i < result.size(); i++) {
		if (count(result.begin() + i, result.end(), result[i]) > 1) {
			*answer -= 1;
			break;
		}
	}
}


void combi(int start, vector <vector <string>> clothes, vector <string> result, int k, int *answer) {
	
	if (result.size() == k) {
		print(result, answer);
		return;
	}
	
	for (int i = start + 1; i < clothes.size(); i++) {
		result.push_back(clothes[i][1]);
		combi(i, clothes, result, k, answer);
		result.pop_back();
	}
    
	return;
    
}


int solution(vector<vector<string>> clothes) {
	int answer = 0;

	vector <string> result;

	for (int i = 1; i <= clothes.size(); i++)
		combi(-1, clothes, result, i, &answer);

	return answer;
}
