#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int T;
    cin >> T; // 테스트 케이스 개수

    while (T--) {
        int K;
        cin >> K;

        priority_queue<long long, vector<long long>, greater<>> pq;

        for (int i = 0; i < K; ++i) {
            long long size;
            cin >> size;
            pq.push(size); // 파일 크기 입력
        }

        long long total = 0;
        while (pq.size() > 1) {
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            total += a + b;
            pq.push(a + b); // 합친 결과를 다시 큐에
        }

        cout << total << "\n";
    }

    return 0;
}
