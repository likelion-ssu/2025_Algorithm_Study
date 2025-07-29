// boj 2294: 동전 2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e9; // 충분히 큰 수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> coin(n);
    for (int i = 0; i < n; ++i) {
        cin >> coin[i];
    }

    vector<int> dp(k + 1, MAX);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = coin[i]; j <= k; ++j) {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }

    if (dp[k] == MAX) cout << -1 << '\n';
    else cout << dp[k] << '\n';

    return 0;
}
