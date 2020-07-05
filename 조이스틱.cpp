#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int SIZE = 26;

int solution(string name) {
	int answer = 0;

	//���ĺ� ������, ������ �̵� Ƚ�� �����ϴ� ����
	vector <pair <int, int>> alpha;
	//�¿�� ������ �Ÿ�
	vector <int> distance;

	//���ĺ� ����
	for (int i = 0; i < name.size(); i++) {
		if (name[i] != 'A')
			alpha.push_back(make_pair(name[i] - 'A', SIZE - (name[i] - 'A')));
	}

	int Acount = 0;
	int count = -1;
	//������
	for (int i = 0; i < name.size(); i++) {
		if (Acount > 0 && name[i] != 'A') {
			Acount = 0;
		}
		else if (i + 1 == name.size() && name[i] == 'A') {
			count -= Acount;
			break;
		}
		else if (name[i] == 'A') {
			Acount++;
		}
		
		//�̵��Ÿ� ������Ŵ
		count++;
	}
	if (count < 0)
		count = 0;

	distance.push_back(count);
	
	
	//������
	count = -1; // count�� �̵��Ÿ�
	Acount = 0; // ���ӵǴ� A�� ����
	int reverse_idx = -1; // ���������� ������ ư ������ �ε���
	for (int i = 0; i < name.size();) {
		
		//���������� ���ٰ� ���������� ư ������ �ε����� ������ ��, �� ������ ��
		if (name.size() - (i+1) == reverse_idx) {
			count -= Acount;
			break;
		}
		//���������� ���� ���� A�� �����ٰ� ��� ���µ� A�� �ƴ� �ٸ� ���ĺ��� ���� ���
		else if (reverse_idx != -1 && Acount > 0 && name.size() - (i + 1) >= 0 && name[name.size() - (i + 1)] != 'A') {
			Acount = 0;
		}
		//���������� ���� ���� A�� ������ �� 
		else if (reverse_idx != -1 && name.size() - (i + 1) >= 0 && name[name.size() - (i + 1)] == 'A') {
			Acount++;
		}
		else if (reverse_idx == -1 && name[i] == 'A') {
			reverse_idx = i;
			if (count == -1)
				count = 0;
			else {
				count += count; //������ ������ �ű��
			}
			i = 0; //�ε����� 0���� �ʱ�ȭ
			continue;
		}
		i++;
		count++;
	}
	distance.push_back(count);

	//���������� ���µ� A�� �ΰ� �̻� �پ��ִ� ��쿡�� ������ ���� ���
	int i = 0;
	reverse_idx = -1;
	count = -1;
	while (1) {
		//���������� ���ٰ� ���������� ư ������ �ε����� ������ ��, �� ������ ��
		if (name.size() - (i + 1) == reverse_idx) {
			count -= Acount;
			break;
		}
		//���������� ���� ���� A�� �����ٰ� ��� ���µ� A�� �ƴ� �ٸ� ���ĺ��� ���� ���
		else if (reverse_idx != -1 && Acount > 0 && name.size() - (i + 1) >= 0 && name[name.size() - (i + 1)] != 'A') {
			Acount = 0;
		}
		//���������� ���� ���� A�� ������ �� 
		else if (reverse_idx != -1 && name.size() - (i + 1) >= 0 && name[name.size() - (i + 1)] == 'A') {
			Acount++;
		}
		else if (name[i] == 'A' && i + 1 < name.size() && name[i + 1] == 'A') {
			reverse_idx = i;
			if (count == -1)
				count = 0;
			else {
				count += count; //������ ������ �ű��
			}
			i = 0; //�ε����� 0���� �ʱ�ȭ
			continue;
		}
		i++;
		count++;
	}
	distance.push_back(count);

	vector <int> sum;
	for (int i = 0; i < alpha.size(); i++) {
		sum.push_back(alpha[i].first < alpha[i].second ? alpha[i].first : alpha[i].second);
	}
	sort(distance.begin(), distance.end());
	sum.push_back(distance[0]);

	for (int i = 0; i < sum.size(); i++)
		answer += sum[i];



	for (int i = 0; i < distance.size(); i++)
		cout << distance[i] << endl;

	cout << answer << endl;



	return answer;
}

int main() {
	
	string name = "CANAAAAANAN";

	solution(name);
}