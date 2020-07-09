#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b) {
	return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
	bool answer = true;

	//우선 각 전화번호를 크기 순서로 정렬
	sort(phone_book.begin(), phone_book.end(), compare);
	
	//서로 크기와 번호가 같아도 접두어 관계가 된다. 
	for (int i = 0; i < phone_book.size(); i++) {
		string temp = phone_book[i];
		for (int j = i + 1; j < phone_book.size(); j++) {
			if ((int)phone_book[j].find(temp) == 0)
				return false;
		}
	}
	return answer;
}

int main() {
	//vector <string> phone = { "119", "97674223", "1195524421" };
	vector <string> phone = { "12", "123", "1235", "567", "88" };

	solution(phone);
}