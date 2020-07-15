#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> divisor(int n) {

    vector <int> div;

    for (int i = n; i >= 1; i--) {
        if (n % i == 0 && find(div.begin(), div.end(), n / i) == div.end()) {
            div.push_back(i);
        }
        else if (find(div.begin(), div.end(), n / i) != div.end()) {
            break;
        }
    }

    return div;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    vector <int> div = divisor(yellow); //약수 구함. 

    for (auto d : div) {

        int row = d + 2;
        int col = yellow / d + 2;

        if (row * col < brown + yellow) {

            for (; row*col < brown + yellow; row += 2, col += 2);

        }

        if (row * col == brown + yellow) {
            answer.push_back(row);
            answer.push_back(col);
            break;
        }
    }

    return answer;
}
