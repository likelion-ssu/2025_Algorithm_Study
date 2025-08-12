#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // dp[i] = i kg을 만들기 위한 최소 봉지 수
    // 초기값 = 불가능
    vector<int> dp(N + 1, 1e9);

    dp[0] = 0; // 0kg을 만들기 위해 봉지 0개 필요

    // 1kg부터 Nkg까지 순서대로 계산
    for (int i = 1; i <= N; ++i) {
        // 3kg 봉지 추가하는 경우
        if (i >= 3 && dp[i - 3] != 1e9) {
            dp[i] = min(dp[i], dp[i - 3] + 1);
        }
        // 5kg 봉지 추가하는 경우
        if (i >= 5 && dp[i - 5] != 1e9) {
            dp[i] = min(dp[i], dp[i - 5] + 1);
        }
    }

    // dp[N] = 초기값
    if (dp[N] == 1e9) {
        cout << -1 << '\n';
    } else {
        cout << dp[N] << '\n'; // 최소 봉지 수 출력
    }

    return 0;
}
