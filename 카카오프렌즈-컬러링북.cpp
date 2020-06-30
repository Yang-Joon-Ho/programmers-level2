#include <vector>
#include <iostream>
using namespace std;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture) {

	int number_of_area = 0;
	int max_size_of_one_area = 0;
	
	/*����� �� 
	1. ���� �� ����
	2. �� 
	3. ������ �� ����
	4. ����
	5. ������
	6. ���� �Ʒ� ����
	7. �Ʒ�
	8. ������ �Ʒ� ����
	*/
	/*�ٸ� ��� �� ������
	���̸� ��� ���ϴ� ������� �ϸ� �ȵǳ�
	
	������, �׸��� �Ʒ� ���⸸ ����Ѵ�. ���ڰ� ��� ������ �����ϳ�
	���� ���ڰ� ����⸦ ������ �Ʒ��� �������ٰ� �¿쿡 �� ������ ������ �ش� ��ġ ����ϰ� ��� �Ʒ���
	������, �׸��� �� ���������� ����� ��ġ�� ���ƿͼ� */

	/*�켱 �湮 ���θ� Ȯ���ϴ� ť�� �ϳ� �ʿ�, �׸��� �� ó���� 
	���� ���� ���� ���Ҹ� �о�ְ�, �װ� �������� ������ �͵��� ť�� ��� �߰��Ѵ�
	�� ó���� ù ���ҿ� ������ �͵��� �о�ְ�, ������ ����.
	�׸���, ù��° ���� ��������, �� ���� ���� �������� �� ������ �� ť�� �߰��Ѵ�. �׷���
	���⼭ �湮�� ���� �ִ� ��ǥ�� �����ϰ� �湮������ ���� ��ǥ�� üũ�ؾ� �Ѵ�. 
	
	�׷��Ƿ� �����غ��� �ΰ��� ������ �̷���� ��ǥ�� �����ϴ� ť�� �ʿ��ϰ�,
	�湮 ���θ� üũ�ϴ� 2���� �迭�� �ʿ��ϴ�. �������� �Լ��� ��ǲ���� ���� 2���� �迭
	���� �湮�Ѱ��� ���Ҹ� 0���� �ٲٸ� �� �� ����. */
	
	vector <pair<int, int>> q;
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {			
			
			//�׸����� �� ĭ�� 0�� �ƴ� ���
			if (picture[i][j] != 0) {
				//������ ������ �ϳ��� �þ
				number_of_area++;

				//�� ������ �ʺ� �ӽ÷� �����ϴ� ���� 
				int max_temp = 0;

				q.push_back(make_pair(i, j));
				
				//�ش� ���� ���
				int temp = picture[i][j];

				//ť�� �� �� �� ����
				while (!q.empty()) {
					//���� ���� ��ǥ
					int x = q.front().first;
					int y = q.front().second;

					picture[x][y] = 0;

					//��
					if (y + 1 < n && temp == picture[x][y + 1]) {
						picture[x][y + 1] = 0;
						q.push_back(make_pair(x, y + 1));
												
					}
					//��
					if (x + 1 < m && temp == picture[x + 1][y]) {
						picture[x + 1][y] = 0;
						q.push_back(make_pair(x + 1, y));
					}
					//��
					if (y - 1 >= 0 && temp == picture[x][y - 1]) {
						picture[x][y - 1] = 0;
						q.push_back(make_pair(x, y - 1));
					}
					//��
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
			else { //�׸����� �ش� ĭ�� 0�� ���
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