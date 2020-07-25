#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;

	vector <string> temp = { words.front() };

	for (vector <string>::iterator it = words.begin() + 1; it != words.end(); it++) {
	
		if (temp.back().back() != (*it).front()) break;
		else if (find(words.begin(), it, *(it)) != it) break;
		else temp.push_back(*it);
	}
	
	if (temp.size() == words.size()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else{
		answer.push_back(temp.size() % n + 1);
		answer.push_back(temp.size() / n + 1);
	}
    
	return answer;
}
