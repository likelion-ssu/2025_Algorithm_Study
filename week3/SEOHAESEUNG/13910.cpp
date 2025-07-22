    #include <bits/stdc++.h>
    using namespace std;

    int n, m;
    int wuk[110];
    int dp[10100];
    set <int> s;

    int f(int last) {
        if(last == 0) return 0;
        if(last < 0) return -1;
        if(dp[last] != 0) return dp[last];

        int best = -1;

        if(s.empty()) return -1;

        for(int i : s) {
            int tmp = f(last - i);
            if(tmp == -1) continue;
            if(best == -1) best = tmp + 1;
            else best = best < tmp + 1 ? best : tmp + 1;
        }

        dp[last] = best;
        return dp[last];
    }

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        cin >> n >> m;

        for(int i = 0; i < m; i++) {
            cin >> wuk[i];
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                if(i == j) s.insert(wuk[i]);
                else s.insert(wuk[i] + wuk[j]);
            }
        }

        for(int i : s) {
            if(i <= n)
            dp[i] = 1;
        }

        cout << f(n) << "\n";

        return 0;
    }