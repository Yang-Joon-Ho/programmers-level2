#include <vector>
#include <iostream>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {

	int number_of_area = 0;
	int max_size_of_one_area = 0;
	
	/*경우의 수 
	1. 왼쪽 위 구석
	2. 위 
	3. 오른쪽 위 구석
	4. 왼쪽
	5. 오른쪽
	6. 왼쪽 아래 구석
	7. 아래
	8. 오른쪽 아래 구석
	*/
	/*다른 방법 뭐 있을까
	널이면 고려 안하는 방법으로 하면 안되나
	
	오른쪽, 그리고 아래 방향만 고려한다. 십자가 모양 영역은 어찌하나
	먼저 십자가 꼭대기를 만나면 아래로 내려가다가 좌우에 또 영역이 있으면 해당 위치 기억하고 계속 아래로
	내려감, 그리고 다 내려갔으면 기억한 위치로 돌아와서 */

	/*우선 방문 여부를 확인하는 큐가 하나 필요, 그리고 맨 처음에 
	왼쪽 구석 위의 원소를 밀어넣고, 그걸 기준으로 인접한 것들을 큐에 계속 추가한다
	맨 처음에 첫 원소와 인접한 것들을 밀어넣고, 개수를 센다.
	그리고, 첫번째 원소 빼버리고, 그 다음 원소 기준으로 또 인접한 것 큐에 추가한다. 그런데
	여기서 방문한 적이 있는 좌표는 제외하고 방문한적이 없는 좌표만 체크해야 한다. 
	
	그러므로 종합해보면 두개의 정수로 이루어진 좌표를 저장하는 큐가 필요하고,
	방문 여부를 체크하는 2차원 배열이 필요하다. 내생각에 함수의 인풋으로 들어온 2차원 배열
	에서 방문한것은 원소를 0으로 바꾸면 될 것 같다. */
	
	vector <pair<int, int>> q;
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {			
			
			//그림에서 한 칸이 0이 아닌 경우
			if (picture[i][j] != 0) {
				//영역의 갯수가 하나씩 늘어남
				number_of_area++;

				//한 영역의 너비를 임시로 저장하는 변수 
				int max_temp = 0;

				q.push_back(make_pair(i, j));
				
				//해당 원소 기억
				int temp = picture[i][j];

				//큐가 다 빌 때 까지
				while (!q.empty()) {
					//기준 점의 좌표
					int x = q.front().first;
					int y = q.front().second;

					picture[x][y] = 0;

					//우
					if (y + 1 < n && temp == picture[x][y + 1]) {
						picture[x][y + 1] = 0;
						q.push_back(make_pair(x, y + 1));
												
					}
					//하
					if (x + 1 < m && temp == picture[x + 1][y]) {
						picture[x + 1][y] = 0;
						q.push_back(make_pair(x + 1, y));
					}
					//좌
					if (y - 1 >= 0 && temp == picture[x][y - 1]) {
						picture[x][y - 1] = 0;
						q.push_back(make_pair(x, y - 1));
					}
					//상
					if (x - 1 >= 0 && temp == picture[x - 1][y]) {
						picture[x - 1][y] = 0;
						q.push_back(make_pair(x - 1, y));
					}
					q.erase(q.begin());
					max_temp++;
				}
				if (max_size_of_one_area < max_temp)
					max_size_of_one_area = max_temp;
			}
			else { //그림에서 해당 칸이 0인 경우
				continue;
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main() {
	int m = 6;
	int n = 4;

	vector<vector<int>> picture = { { 1, 1, 1, 0 },{ 1, 1, 1, 0 },{ 0, 0, 0, 1 },{ 0, 0, 0, 1 },{ 0, 0, 0, 1 },{ 0, 0, 0, 1 } };
	
	solution(6, 4, picture);
}