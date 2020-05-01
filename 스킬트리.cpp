#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
   	int answer = 0;
	reverse(skill.begin(), skill.end());
	string str = skill;

	for (int i = 0; i < skill_trees.size(); i++) {
		string temp = str;
		int j;
		for (j = 0; j < skill_trees[i].size(); j++) {
			if (temp.find(skill_trees[i][j], 0) < temp.size()) {
				//cout << temp.find(skill_trees[i][j]) << endl;
				if (temp[temp.size() - 1] != skill_trees[i][j])
					break;
				else
					temp.pop_back();
			}
		}
		if (j == skill_trees[i].size()) {
			answer++;
		}
	} 
    
    return answer;
}
