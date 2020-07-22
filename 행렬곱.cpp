#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	
	vector<vector<int>> answer;

	for (int i = 0; i < arr1.size(); i++) {
		vector <int> v;
		for (int k = 0; k < arr2[0].size(); k++) {
			int temp = 0;
			for (int j = 0; j < arr1[i].size(); j++) {
				temp += arr1[i][j] * arr2[j][k];
			}
			v.push_back(temp);
		}
		answer.push_back(v);
	}

	return answer;
}
