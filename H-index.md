[문제](https://programmers.co.kr/learn/courses/30/lessons/42747)
-----------------------------

<br>
<br>

### 1. 코드 
```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<int>());
    
    for(int i = 0; i < citations.size(); i++) {
        if(citations[i] <= answer) break;
        answer++;
    }
    
    return answer;
}
```

<br>

### 2. 코멘트

    인용횟수를 내림차순으로 정렬해 놓고, answer를 증가시키면서 
    i번째 논문의 인용횟수가 answer 이하이면 논문 목록에서 해당 논문은 answer회 이상 인용되거나
    answer회 이하로 인용되었다. 
