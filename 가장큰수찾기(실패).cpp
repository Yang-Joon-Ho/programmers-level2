#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string solution(vector<int> numbers) {
	string answer = "";

	vector <pair<int, string>> standard;
	vector <string> combi;

	/*
	89
	8
	���ڸ��� ���� ������� ���ڸ��� ���ϴµ� 
	���� ���ϴ� �� ���� �ڸ����� ���� ���� �ʴ� ���
	�ڸ����� ������ ���� ���ڸ��� �ڸ����� ���� ���� ���ڸ��� 
	��
	889 < 898
	8�� 89�� ��� ���ϸ� ������
	�ϴ� ���� �������� ã�´�.
	���� �����ͳ��� ������ �Ѵ�. 
	ó���� �� �ε����� �����ؼ� ���� ������ ������ �ȴ�.
	*/

	//�� ���ڸ����� �̿��� 1�� ����
	for (int i = 0; i < numbers.size(); i++) {
		
		string temp_string = to_string(numbers[i]);
		
		int temp_int = temp_string[0] - '0';
		standard.push_back(make_pair(temp_int, temp_string));
	}
	sort(standard.begin(), standard.end());
		
	int idx = 0; //temp_string���� ���� �ε��� 
	int same = 0;
	for (int i = 0; i < standard.size(); ) {
		
		int same = 1;
		int prev = i; //���� ���ڵ��� ���۵Ǵ� �ε���
		while (prev + 1 < standard.size() && standard[prev].first == standard[prev + 1].first) {
			same++;
			prev++;
		}

		for (int idx = 0; idx < 5; idx++) {
			for (int j = i; j < i + same; j++) {
				if (standard[j].second[idx + 1])
					standard[j].first = standard[j].second[idx + 1] - '0';
			}
			sort(standard.begin() + i, standard.begin() + i + same);
		}
		i += same;
	}

	standard;

	return answer;
}

int main() {
	vector <int> numbers = { 89,19,15, 8 };
	solution(numbers);

}