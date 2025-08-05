#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> sensors(N);
    for (int i = 0; i < N; ++i) cin >> sensors[i];

    if (K >= N) {
        cout << 0 << "\n"; // 센서보다 집중국이 많으면 거리합은 0
        return 0;
    }

    sort(sensors.begin(), sensors.end());

    vector<int> diffs;
    for (int i = 1; i < N; ++i)
        diffs.push_back(sensors[i] - sensors[i - 1]); // 인접 거리

    sort(diffs.rbegin(), diffs.rend()); // 내림차순 정렬

    int result = accumulate(diffs.begin() + K - 1, diffs.end(), 0); // K-1개 제거 후 합산
    cout << result << "\n";
    return 0;
}
