#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b) {
	int answer;

	vector <int> ab{ a, b };
	sort(ab.begin(), ab.end());

	int temp = n;
	int depth = 0;

	while (temp /= 2) depth++;

	temp = n;
	while (temp /= 2) {
		if (ab[0] <= temp && ab[1] > temp) break;
		
		else if(ab[0] <= temp && ab[1] <= temp) depth --;
		
		else {
			ab[0] -= temp, ab[1] -= temp; 
			depth --;
		}
	}

	return depth;
}
