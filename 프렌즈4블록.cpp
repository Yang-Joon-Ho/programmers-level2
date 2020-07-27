#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = m * n;

	vector<vector <int>> copy;
	
	for (int i = 0; i < board.size(); i++) {
		vector <int> temp;
		for (int j = 0; j < board[i].size(); j++) 
			temp.push_back(0);

		copy.push_back(temp);
	}

	while (1) {
		vector<vector <int>> copy_temp = copy;
		for (int i = 1; i < board.size(); i++) {
			for (int j = 1; j < board[i].size(); j++) {
				if (board[i][j] != '0' &&
					board[i - 1][j - 1] == board[i][j] &&
					board[i - 1][j] == board[i][j] &&
					board[i][j - 1] == board[i][j]) {
					
					copy_temp[i - 1][j - 1] = 1;
					copy_temp[i - 1][j] = 1;
					copy_temp[i][j - 1] = 1;
					copy_temp[i][j] = 1;
				}
			}
		}

		bool change = false;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (copy_temp[i][j]) { // 위의 인형들을 빈공간으로 당김
					for (int k = i; k >= 0; k--) {
						if (k == 0)
							board[k][j] = '0';
						else
							board[k][j] = board[k - 1][j];
					}
					change = true;
				}
			}	
		}
		if(!change)
			break;
	}

	for (auto i : board) {
		for (auto j : i) {
			if (j != '0')
				answer--;
		}
	}

	return answer;
}

int main() {

	vector<string>board = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
	solution(board.size(), board[0].size(), board);

}
