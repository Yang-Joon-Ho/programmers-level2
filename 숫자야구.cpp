#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    for (int i = 123; i <= 987; i++) {
        int x = i / 100; int y = (i / 10) % 10; int z = i % 10;
        if ((x == y)  || (y == z) || (z == x)) continue;
        if (x == 0 || y == 0 || z == 0) continue;

        for (int j = 0; j < baseball.size(); j++) {
            int strike = 0;
            int ball = 0;

            int problem = baseball[j][0];
            int problem_X = problem / 100;
            int problem_Y = (problem / 10) % 10;
            int problem_Z = problem % 10;

            if (problem_X == 0 || problem_Y == 0 || problem_Z == 0) break;
            if (problem_X == x) strike++; if (problem_Y == y) strike++; if (problem_Z == z) strike++;
            if (baseball[j][1] != strike) break;

            if (problem_Y == x || problem_Z == x) ball++; if (problem_X == y || problem_Z == y) ball++; if (problem_X == z || problem_Y == z) ball++;
            if (baseball[j][2] != ball) break;
            if (j == baseball.size() -1) answer++;
        }
    }
    return answer;
}
