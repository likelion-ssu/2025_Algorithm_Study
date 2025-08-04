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

    // 모든 센서에 집중국 하나씩 설치 가능할 때, 수신 길이 0
    if (K >= N) {
        cout << 0 << endl;
        return 0;
    }

    sort(sensors.begin(), sensors.end());

    // 인접 센서 간 거리 저장
    vector<int> diffs;
    for (int i = 1; i < N; ++i) {
        diffs.push_back(sensors[i] - sensors[i - 1]);
    }

    // 가장 큰 거리부터 제거 - 내림차순 정렬
    sort(diffs.begin(), diffs.end(), greater<int>());

    // 가장 큰 (K-1)개의 거리를 제외하고 나머지 합을 계산
    int min_total_length = 0;
    for (int i = K - 1; i < diffs.size(); ++i) {
        min_total_length += diffs[i];
    }

    cout << min_total_length << endl;

    return 0;
}
