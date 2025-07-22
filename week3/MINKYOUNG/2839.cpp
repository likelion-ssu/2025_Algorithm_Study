// boj 2839: 설탕배달 (DP)
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    const int MAX = 1e9;
    int dp[5001];

    for (int i = 0; i <= N; ++i) dp[i] = MAX;
    dp[0] = 0;

    for (int i = 1; i <= N; ++i) {
        if (i >= 3) dp[i] = min(dp[i], dp[i - 3] + 1);
        if (i >= 5) dp[i] = min(dp[i], dp[i - 5] + 1);
    }

    if (dp[N] == MAX)
        cout << -1 << '\n';
    else
        cout << dp[N] << '\n';

    return 0;
}
