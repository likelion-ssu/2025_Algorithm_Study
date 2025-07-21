#include <bits/stdc++.h>
#define STRAWBERRY 0
#define CHOCO 1
#define BANANA 2
using namespace std;

int area[1010][1010]; 
int dp[1010][1010][3];  // 행, 열, 가장 최근에 먹은 맛
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
        cin >> area[i][j];
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            dp[0][i][j] = INT_MIN;
            dp[i][0][j] = INT_MIN;
        }   
    }

    dp[0][1][BANANA] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            // 기존 최대 상태 가져오기
            dp[i][j][BANANA] = max(dp[i - 1][j][BANANA], dp[i][j - 1][BANANA]);
            dp[i][j][CHOCO] = max(dp[i - 1][j][CHOCO], dp[i][j - 1][CHOCO]);
            dp[i][j][STRAWBERRY] = max(dp[i - 1][j][STRAWBERRY], dp[i][j - 1][STRAWBERRY]);

            int current_flavor = area[i][j];

            // 현재 위치의 맛을 먹는 상태, 현재 위치의 맛을 가장 최근에 먹었지만 현재 위치는 먹지 않은 상태 비교
            dp[i][j][current_flavor] = max(dp[i][j][current_flavor], dp[i][j][(current_flavor - 1 + 3) % 3] + 1);
        }
    }

    // 마지막에 먹은 맛에 따른 dp값 모두 비교
    int res = max({dp[n][n][STRAWBERRY], dp[n][n][CHOCO], dp[n][n][BANANA]});
    
    cout << res << "\n";


    return 0;
}