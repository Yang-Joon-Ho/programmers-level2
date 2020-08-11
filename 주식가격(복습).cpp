#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size(), 0);

	for (int i = 0; i < prices.size(); i++) {
		
		int j = i;
		if (i + 1 == prices.size()) break;
		
		do {
			answer[i]++;
			j++;
			if (j + 1 == prices.size()) break;

		} while(prices[i] <= prices[j]);
	}

	return answer;
}

int main() {
	vector<int> prices{ 1,2,3,2,3 };
	
	solution(prices);
}
