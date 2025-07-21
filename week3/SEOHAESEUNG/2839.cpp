#include <bits/stdc++.h>
using namespace std;

int dp[5050];

int f(int weight) {
    if(dp[weight] > 0) return dp[weight];
    if(weight == 3) return 1;
    if(weight == 5) return 1;
    if(weight < 5) return 50000;

    dp[weight] = min(f(weight - 3), f(weight - 5)) + 1;

    return dp[weight];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int res = f(n);

    if(res >= 50000) {
        cout << "-1\n";
        return 0;
    }
    cout << res << "\n";

    return 0;
}