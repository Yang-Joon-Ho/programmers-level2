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

    sort(citations.begin(), citations.end(), greater<int>());
    
    int i;
    for (i = 0; i < citations.size(); i++) {
        if(citations[i] <= i) break;
    }
    
    return i;
}
```

<br>

### 2. 코멘트

    인용횟수를 내림차순으로 정렬해 놓고, answer를 증가시키면서 
    i번째 논문의 인용횟수가 answer 이하이면 논문 목록에서 해당 논문은 answer회 이상 인용되거나
    answer회 이하로 인용되었다. 
    
    논문의 인용 횟수와 상관없이 h번 이상 인용된 논문이 h편 이상인것 중에 가장 큰 h이면 됨. 
    예를 들어 논문 목록이 다음과 같다면 { 7, 6, 4, 1, 1, 0}
    
    3번 이상 인용된 논문이 3편이므로 h-index = 3임. 
