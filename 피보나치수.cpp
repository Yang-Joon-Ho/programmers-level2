#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int solution(int n)
{
    vector <int> f;
    f.push_back(0);
    f.push_back(1);

    for (int i = 2; i <= n; i++) f.push_back((f[f.size() - 2] % 1234567 + f[f.size() - 1] % 1234567) % 1234567);

    return f[f.size() - 1];
}
