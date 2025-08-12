#include <bits/stdc++.h>
using namespace std;

int n, k;
queue <pair<int, int>> water; // BFS를 위한 큐 ({위치, 불행도})
unordered_set <int> used; // 해당 인덱스가 이미 확인됐는지 확인

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    long long res = 0; // 결과 저장
    int build_house = 0; // k개를 지었는지 확인하는 변수

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        water.push({tmp, 0});
        used.insert(tmp);
    }

    while(build_house < k) {
        pair <int, int> tmp = water.front();
        water.pop();

        // index 앞칸 확인
        if(!used.count(tmp.first - 1)) {
            res += tmp.second + 1;
            water.push({tmp.first - 1, tmp.second + 1});
            used.insert(tmp.first - 1);
            build_house++;
        }
        // 집을 모두 지은 경우
        if(build_house >= k) break;

        // index 뒷칸 확인
        if(!used.count(tmp.first + 1)) {
            res += tmp.second + 1;
            water.push({tmp.first + 1, tmp.second + 1});
            used.insert(tmp.first + 1);
            build_house++;
        }

        
    }

    cout << res << "\n";
 
    return 0;
}