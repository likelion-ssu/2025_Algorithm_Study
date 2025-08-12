// boj 2212: 센서
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N, K;
    cin >> N >> K;

    vector<int> sensors(N);
    for (int i = 0; i < N; ++i) {
        cin >> sensors[i];
    }

    if (K >= N) {
        cout << 0 << '\n';
        return 0;
    }

    sort(sensors.begin(), sensors.end());

    // 센서 사이 거리 차이
    vector<int> diffs;
    for (int i = 1; i < N; ++i) {
        diffs.push_back(sensors[i] - sensors[i - 1]);
    }

    sort(diffs.begin(), diffs.end(), greater<>());

    // 큰 거리 제거하ㄱ
    int result = 0;
    for (int i = K - 1; i < diffs.size(); ++i) {
        result += diffs[i];
    }

    cout << result << '\n';
    return 0;
}

// 최대 K개의 집중국
// N개의 센서가 적어도 하나의 집중국과는 통신해야함
// 각 집중국의 수신 가능 영역의 길이의 합을 최소화

// 각 집중국의 수신 가능 영역의 거리의 합의 최솟값 구하기
