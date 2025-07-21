#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dp[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> coin(n);
    for (int i = 0; i < n; ++i) {
        cin >> coin[i];
    }

    // DP 배열 초기화
    fill(dp, dp + k + 1, INF);
    dp[0] = 0; // 0원을 만들기 위한 동전 수는 0개

    // DP 점화식 적용
    for (int c : coin) {
        for (int i = c; i <= k; ++i) {
            dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }

    cout << (dp[k] == INF ? -1 : dp[k]) << "\n";
    return 0;
}
