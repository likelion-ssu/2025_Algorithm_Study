#include <bits/stdc++.h>
using namespace std;

int n, m;
int dis[110][110];

int get_sum(int first_chicken, int second_chicken) {
    int res = 0;
    for(int i = 0; i < n; i++) {
        res += min(dis[i][first_chicken], dis[i][second_chicken]) * 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int a, b;

    // 초기화
    for(int i = 0; i < 110; i++) {
        for(int j = 0; j < 110; j++)
        if(i == j) dis[i][j] = 0;
        else dis[i][j] = 1000000;
    }

    // 경로 입력
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        dis[a - 1][b - 1] = 1;
        dis[b - 1][a - 1] = 1;
    }

    // 플로이드-와샬 알고리즘으로 최단 경로 구하기(j -> k)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                dis[j][k] = min(dis[j][i] + dis[i][k], dis[j][k]);
            }
        }
    }

    int res_a = 0;
    int res_b = 1;
    int res_c = get_sum(0, 1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(res_c > get_sum(i, j)) {
                res_a = i;
                res_b = j;
                res_c = get_sum(i, j);
            }
        }
    }

    cout << res_a + 1 << " " << res_b + 1 << " " << res_c << "\n";

    return 0;
}