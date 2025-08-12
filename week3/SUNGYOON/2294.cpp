#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i]; // 동전 가치 입력
    }

    // dp[i] = i원을 만들기 위한 최소 동전 개수
    vector<int> dp(k + 1, 1e9); // 초기값 = 불가능
    dp[0] = 0; // 0원은 동전 0개로 만들 수 있음

    // 모든 동전에 대해 반복
    for (int i = 0; i < n; ++i) {
        int coin = coins[i];
        // 현재 동전으로 만들 수 있는 금액부터 k까지 반복
        for (int j = coin; j <= k; ++j) {
            // (j - coin)을 만들 수 있다면, 거기에 coin 하나 더한 것
            if (dp[j - coin] != 1e9) {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }
    }

    // dp[k] = 초기값
    if (dp[k] == 1e9) {
        cout << -1 << '\n';
    } else {
        cout << dp[k] << '\n';
    }

    return 0;
}
