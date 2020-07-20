#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;

	vector <int> temp = nums;
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());

	return min(temp.size(), nums.size() / 2);
}
