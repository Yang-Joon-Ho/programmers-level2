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

	//�켱 �� ��ȭ��ȣ�� ũ�� ������ ����
	sort(phone_book.begin(), phone_book.end(), compare);
	
	//���� ũ��� ��ȣ�� ���Ƶ� ���ξ� ���谡 �ȴ�. 
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