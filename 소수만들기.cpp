#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

vector<vector<int>> result;
int len = 3;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if ((n%i) == 0) {
            return false;
        }
    }

    return true;
}

void ser(vector <int> nums, vector <int> sub, int k) {

    if (sub.size() == len) {
        result.push_back(sub);
    }
    else if (k >= nums.size()) {
        return;
    }
    else {
        sub.push_back(nums[k]);
        ser(nums, sub, k + 1);
        sub.pop_back();
        ser(nums, sub, k + 1);
    }
}

int solution(vector <int> nums)
{
    int answer = 0;

    vector<int> sub;
    ser(nums, sub, 0);

    vector <int> sums;
    for (int i = 0; i < result.size(); i++) {
        int sum = 0;
        for (int k = 0; k < result[i].size(); k++) {
            sum += result[i][k];
        }
        sums.push_back(sum);
    }

    for (auto c : sums) {
        if (isPrime(c)) answer++;
    }

    return answer;
}
