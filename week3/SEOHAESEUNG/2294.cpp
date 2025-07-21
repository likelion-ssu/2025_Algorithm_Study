#include <bits/stdc++.h>
using namespace std;

int n, k;
int coin[110];
int dp[10100];

int f(int v) {
    if(v < 0) return 10100;
    if(v == 0) return 0;
    if(dp[v] > 0) return dp[v];
    int res = 10100;

    for(int i = 0; i < n; i++) {
        res = min(res, f(v - coin[i]));
    }
    dp[v] = res + 1;

    return dp[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    if(f(k) >= 10100) {
        cout << "-1\n";
        return 0;
    }

    cout << f(k) << "\n";

    return 0;
}