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
	
	//숫자 조합을 먼저 구해야 함
	//한자리일 때, 두자리 일때, n자리 일 때 다 고려해야 함
	vector <int> vec;
	//vector에 초기값 넣기
	//string numbers를 벡터로 바꿈 
	vector <int> vec_num;
	for (int i = 0; i < numbers.size(); i++) {
		vec.push_back(numbers[i] - '0');
		vec_num.push_back(numbers[i] - '0');
	}

	int idx = 0;
	while (1) {
		
		//현재 인덱스의 벡터 값을 분해한다. 
		vector <int> temp_vec;
		int temp = vec[idx];
		do {
			temp_vec.push_back(temp % 10);
		} while (temp /= 10);
			
		//더이상 vec에 추가할 것이 없으면 반복문을 빠져나온다. 
		if (temp_vec.size() == numbers.size())
			break;

		//temp_num에 num에서 temp_vec에 있는 것을 제외한 것을 넣는다.
		vector <int> temp_num = vec_num;
		for (int i = 0; i < temp_vec.size(); i++) {
			temp_num.erase(find(temp_num.begin(), temp_num.end(), temp_vec[i]));
		}

		//vec 현재 인덱스의 숫자에 temp_num의 각 숫자를 차례로 붙여서 vec에 추가한다.
		for (int i = 0; i < temp_num.size(); i++) {
			vec.push_back(10 * vec[idx] + temp_num[i]);
		}

		idx++;
	}

	//중복값 제거
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	vec;

	idx = 0;
	do {
		//소수 아니면 삭제
		if (!judge_prime(vec[idx])) 
			vec.erase(find(vec.begin(), vec.end(), vec[idx]));
		
		//소수가 아닌 숫자는 삭제하므로 소수라고 판정됬을 경우에만 인덱스를 증가 시킨다.
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