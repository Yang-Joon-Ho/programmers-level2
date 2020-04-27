#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 1;

	reverse(truck_weights.begin(), truck_weights.end());
	vector <pair<int, int>> bridge;

	int sum = 0;
	 do {
		 if (bridge.size() > 0) {
			 for (vector <pair <int, int>>::iterator it = bridge.begin(); it != bridge.end();) {
				 it->second--;
				 if (it->second == 0) {
					 sum -= it->first;
					 it = bridge.erase(it);
					 if (bridge.size() == 0)
						 break;
				 }
				 else {
					 it++;
				 }
			 }
		 }
		 if (truck_weights.size() > 0 && sum + truck_weights.back() <= weight) {
			 sum += truck_weights.back();
			 bridge.push_back(make_pair(truck_weights.back(), bridge_length));
			 truck_weights.pop_back();
		 }
		 else if(truck_weights.size() == 0 && bridge.size() == 0)
		     break;
	 }while(answer++);

	return answer;
}
