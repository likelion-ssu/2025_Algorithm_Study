#include <bits/stdc++.h>
using namespace std;

int c, n;
pair <int, int> city[30];
int dp[10000];

int f(int need) {
    if(need <= 0) return 0;
    if(dp[need] > 0) return dp[need];
    int min_val = INT_MAX;
    for(int i = 0; i < n; i++) {
        int current = f(need - city[i].second) + city[i].first;
        min_val = min_val < current ? min_val : current;
    }

    dp[need] = min_val;

    return dp[need];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> c >> n;

    for(int i = 0; i < n; i++) {
        cin >> city[i].first >> city[i].second;
    }

    cout << f(c) << "\n";
    

    return 0;
}