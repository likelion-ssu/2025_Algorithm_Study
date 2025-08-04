// boj 13975: 파일 합치기3
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 시간 초과 후 추가
    cin.tie(nullptr); 

    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;

        priority_queue<long long, vector<long long>, greater<long long>> pq;  // longlong으로 변경

        for (int i = 0; i < K; ++i) {
            long long file;
            cin >> file;
            pq.push(file);
        }

        long long total_cost = 0;

        while (pq.size() > 1) {
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            total_cost += a + b;
            pq.push(a + b);
        }

        cout << total_cost << '\n';
    }

    return 0;
}
