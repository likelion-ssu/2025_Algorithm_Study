#include <stdio.h>

#define MAX 10001
#define INF 123456789

int coins[MAX];
int dp[MAX];

int main() {
    int n,k;
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &coins[i]);
    }

    for(int i = 1; i <= k; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = coins[i]; j <= k; j++) {
            if(dp[j - coins[i]] + 1 < dp[j]) {
                dp[j] = dp[j - coins[i]] + 1;
            }
        }
    }

    if(dp[k] == INF) printf("-1");
    else printf("%d", dp[k]);

    return 0;
}