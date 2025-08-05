#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;

        // 최소 힙 사용: 항상 가장 작은 파일 2개를 빠르게 꺼내기 위함
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < K; ++i) {
            int file;
            cin >> file;
            pq.push(file);
        }

        long long totalCost = 0;

        // 파일이 하나 남을 때까지 반복
        while (pq.size() > 1) {
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();

            int merged = first + second;
            totalCost += merged;
            pq.push(merged); // 합쳐진 파일 다시 힙에 삽입
        }

        cout << totalCost << '\n';
    }

    return 0;
}
