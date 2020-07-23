#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int baesu(int a, int b) {

	int answer = 1;

	vector <int> arr;
	arr.push_back(a);
	arr.push_back(b);

	vector <int> yaksu;
	for (int i = 1; i <= sqrt(a); i++) {
		if (i == sqrt(a)) {
			yaksu.push_back(i);
		}
		else if (a % i == 0) {
			yaksu.push_back(i);
			yaksu.push_back(a / i);
		}
	}

	sort(yaksu.begin(), yaksu.end(), compare);

	vector <int> num;
	for (auto i : yaksu) {
		vector <int> temp = {};
		for (auto j : arr) {
			if (j % i != 0) break;
			else temp.push_back(j / i);
		}
		if (temp.size() == arr.size()) {
			num.push_back(i);
			arr = temp;
		}
	}

	arr.insert(arr.begin(), num.begin(), num.end());

	for (auto i : arr)
		answer *= i;

	return answer;
}

int solution(vector <int> arr) {
	int answer = 1;

	sort(arr.begin(), arr.end());

	for (vector <int>::iterator it = arr.begin(); arr.size() > 1;) {
		if (it + 1 != arr.end()) {
			*it = *it < *(it + 1) ? baesu(*it, *(it + 1)) : baesu(*(it + 1), *it);
			arr.erase(it + 1);
		}
	}
		
	return arr[0];
				
}
