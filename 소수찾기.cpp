#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

bool judge_prime(int n) {

	if (n <= 1)
		return false;
	else if (n <= 3)
		return true;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) 
			return false;
	}

	return true;
}


int solution(string numbers) {
	int answer = 0;
	
	//���� ������ ���� ���ؾ� ��
	//���ڸ��� ��, ���ڸ� �϶�, n�ڸ� �� �� �� ����ؾ� ��
	vector <int> vec;
	//vector�� �ʱⰪ �ֱ�
	//string numbers�� ���ͷ� �ٲ� 
	vector <int> vec_num;
	for (int i = 0; i < numbers.size(); i++) {
		vec.push_back(numbers[i] - '0');
		vec_num.push_back(numbers[i] - '0');
	}

	int idx = 0;
	while (1) {
		
		//���� �ε����� ���� ���� �����Ѵ�. 
		vector <int> temp_vec;
		int temp = vec[idx];
		do {
			temp_vec.push_back(temp % 10);
		} while (temp /= 10);
			
		//���̻� vec�� �߰��� ���� ������ �ݺ����� �������´�. 
		if (temp_vec.size() == numbers.size())
			break;

		//temp_num�� num���� temp_vec�� �ִ� ���� ������ ���� �ִ´�.
		vector <int> temp_num = vec_num;
		for (int i = 0; i < temp_vec.size(); i++) {
			temp_num.erase(find(temp_num.begin(), temp_num.end(), temp_vec[i]));
		}

		//vec ���� �ε����� ���ڿ� temp_num�� �� ���ڸ� ���ʷ� �ٿ��� vec�� �߰��Ѵ�.
		for (int i = 0; i < temp_num.size(); i++) {
			vec.push_back(10 * vec[idx] + temp_num[i]);
		}

		idx++;
	}

	//�ߺ��� ����
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	vec;

	idx = 0;
	do {
		//�Ҽ� �ƴϸ� ����
		if (!judge_prime(vec[idx])) 
			vec.erase(find(vec.begin(), vec.end(), vec[idx]));
		
		//�Ҽ��� �ƴ� ���ڴ� �����ϹǷ� �Ҽ���� �������� ��쿡�� �ε����� ���� ��Ų��.
		else
			idx++;

	} while (idx < vec.size());

	vec; 

	return vec.size();
	
}

int main() {
	string numbers = "0135";

	solution(numbers);
}