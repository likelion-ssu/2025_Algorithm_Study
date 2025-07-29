// boj 11660: 구간 합 구하기 5
#include <iostream>

using namespace std;

int N, M;
int A[1025][1025]; // 원본 
int B[1025][1025]; // 누적합 

int main() {
    ios::sync_with_stdio(false); // 시간 초과 후 수정 
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> A[i][j];
            B[i][j] = B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1] + A[i][j];
        }
    }

    for (int i = 0; i < M; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int result = B[x2][y2] - B[x1 - 1][y2] - B[x2][y1 - 1] + B[x1 - 1][y1 - 1];
        cout << result << '\n';
    }

    return 0;
}
