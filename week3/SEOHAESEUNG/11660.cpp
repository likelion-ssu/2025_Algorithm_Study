#include <bits/stdc++.h>
using namespace std;

int arr[1050][1050];
long long dp[1050][1050];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
        cin >> arr[i][j];
    }

    pair <int, int> start;
    pair <int, int> end;

    // Bottom-up 방식으로 누적합 저장
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1] + arr[i][j];
        }
    }

    int res = 0;

    // 각 j행마다, end.second열 누적합 - start.second - 1열 누적합 구하기
    for(int i = 0; i < m; i++) {
        res = 0;
        cin >> start.first >> start.second >> end.first >> end.second;
        for(int j = start.first; j <= end.first; j++) {
            res += dp[j][end.second];
            res -= dp[j][start.second - 1];
        }
        cout << res << "\n";
    }


    return 0;
}