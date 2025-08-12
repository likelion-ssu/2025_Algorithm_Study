#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    // N+1 크기의 2차원 벡터 생성
    vector<vector<int>> arr(N + 1, vector<int>(N + 1));
    vector<vector<int>> prefix(N + 1, vector<int>(N + 1, 0)); // 누적합 배열

    // 입력 받기: 원본 배열
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> arr[i][j];
        }
    }

    // DP: 2차원 누적합(prefix sum) 계산
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            // (1,1)부터 (i,j)까지의 합 저장
            prefix[i][j] = arr[i][j]
                         + prefix[i - 1][j]     // 위쪽 누적
                         + prefix[i][j - 1]     // 왼쪽 누적
                         - prefix[i - 1][j - 1]; // 중복된 부분 제거
        }
    }

    // 쿼리 처리
    for (int q = 0; q < M; ++q) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // (x1, y1)부터 (x2, y2)까지의 부분합 계산 
        int result = prefix[x2][y2]
                   - prefix[x1 - 1][y2]
                   - prefix[x2][y1 - 1]
                   + prefix[x1 - 1][y1 - 1];

        cout << result << '\n';
    }

    return 0;
}
