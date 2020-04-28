#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
vector<int> answer(prices.size(), 0);

	for (int front = 0, back = 1; ; back++) {
		if (back == prices.size()) {
			front++;
			if (front == prices.size() - 1)
				break;
			back = front + 1;
		}
		if (prices[front] > prices[back]) { //가격이 하락한 경우
			answer[front]++;
			front++;
            if (front == prices.size() - 1)
				break;
			back = front;
			continue;
		}
		answer[front]++;
	}
    
    return answer;
}
