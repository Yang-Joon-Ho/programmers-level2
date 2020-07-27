#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;

	vector <string> q;

	for (auto c : cities) {
		transform(c.begin(), c.end(), c.begin(), ::tolower);
		// hit
		if (find(q.begin(), q.end(), c) != q.end()) {
			q.push_back(*find(q.begin(), q.end(), c));
			q.erase(find(q.begin(), q.end(), c));
			answer++;  continue;
		}// miss
		else if (q.size() == cacheSize && q.size()) {
			q.erase(q.begin());
		}

		if (cacheSize) q.push_back(c);
		answer += 5;
	}

	return answer;
}
