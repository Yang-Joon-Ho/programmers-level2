#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>&numbers, int &answer, int target, int idx = 0, int sum = 0) {

	//numbers의 마지막 수를 빼냐 더하냐 
	if (idx == numbers.size() - 1) {
		if (target == sum + numbers[idx]) answer++;
		if (target == sum - numbers[idx]) answer++;
		return;
	}

	dfs(numbers, answer, target, idx + 1, sum + numbers[idx]);
	dfs(numbers, answer, target, idx + 1, sum - numbers[idx]);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	
	dfs(numbers, answer, target);

	return answer;
}
