// boj 14425: 문자열 집합
#include <iostream>
#include <set>

using namespace std;

int main() {
    int N, M;
    int count = 0;
    cin >> N >> M;

    string s;
    set<string> set;
    for (int i=0; i<N; i++) {
        cin >> s;
        set.insert(s); // 집합 S에 해당하는 문자열들 set에 저장
    }

    for (int j=0; j<M; j++) {
        cin >> s;
        if (set.find(s) != set.end())
            count++;
    }

    cout << count << "\n";
    return 0;
}

// set 관련 문제 
// N 개의 줄에는 집합 S에 포함되어 있는 문자열들
// M 개의 줄에는 검사해야 하는 문자열들 
// 출력: Mr개의 문자열 중에 총 몇 개가 집합 S에 포함되는가 

// N개를 set에 넣어놓고, M개의 줄을 돌리면서 각 집합에 해당하는 게 있는지 확인 후 카운트 올림

// binary_search를 활용 