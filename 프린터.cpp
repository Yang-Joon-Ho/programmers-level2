#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
int answer = 1;
	
	while (1) {
		if (location == 0) {
			if (priorities.front() == *max_element(priorities.begin(), priorities.end())) 
				return answer;
			else {
				priorities.push_back(priorities.front());
				priorities.erase(priorities.begin());
				location = priorities.size() - 1; //맨 뒤로 보내는 것이므로 
			}
		}
		else if (priorities.front() == *max_element(priorities.begin(), priorities.end())) {
			priorities.erase(priorities.begin());
			answer++;
			location--;
		}
		else {
			priorities.push_back(priorities.front());
			priorities.erase(priorities.begin());
			location--;
		}
	}

	return answer;
}
