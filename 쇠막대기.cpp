#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    
    	vector <char> stack;
	int open_close; //1 is open, 0 is close

	for (int i = 0, size = arrangement.size(); i < size; i++) {
		if (arrangement[i] == ')') {
			if (open_close == 1) {
				open_close = 0;
				stack.pop_back();
				answer += stack.size();
			}
			else {
				stack.pop_back();
				answer += 1;
			}
		}
		else {
			open_close = 1;
			stack.push_back(arrangement[i]);
		}
	}
    
    return answer;
}
