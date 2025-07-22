#include <bits/stdc++.h>
using namespace std;

int n;
pair <int, int> arr[1550000];
long long dp[1550000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    for(int i = 0; i <= n; i++) {
        if(i != 0) {
            if(dp[i] < dp[i - 1]) {
                dp[i] = dp[i - 1];
            }
        }
        int next_index = i + arr[i].first;
        if(next_index > n) continue;
        else {
            int plus_value = dp[i] + arr[i].second;
            dp[next_index] = dp[next_index] > plus_value ? dp[next_index] : plus_value;
        }
    }

    cout << dp[n] << "\n";

    return 0;
}