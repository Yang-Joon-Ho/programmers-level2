#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool compare(string a, string b) {
	return a.size() < b.size();
}

vector<int> solution(string s) {
	vector<int> answer;

	s.erase(s.begin());
	s.erase(s.end() - 1);

	vector<string> v;

	string::iterator it_begin = s.begin();
	string::iterator it_end = it_begin;

	while (!(find(it_begin, s.end(), '{') == s.end())) {
		it_begin = find(it_begin, s.end(), '{') + 1;
		it_end = find(it_begin, s.end(), '}');
		string temp = s.substr(it_begin - s.begin(), it_end - it_begin);
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), compare);
	
	for (auto c : v) {
		istringstream ss(c);
		string buffer;
		while (getline(ss, buffer, ',')) {
			if (find(answer.begin(), answer.end(), stoi(buffer)) == answer.end())
				answer.push_back(stoi(buffer));
		}
	}
		
	return answer;
}
