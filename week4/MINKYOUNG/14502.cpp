// boj 14502: 연구소
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int lab[8][8];
int temp[8][8];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int result = 0;

void copyMap(int dest[8][8], int src[8][8]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            dest[i][j] = src[i][j];
}

void bfs(int map[8][8]) {
    int virus_map[8][8];
    copyMap(virus_map, map);

    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (virus_map[i][j] == 2)
                q.push({i, j});

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && virus_map[nx][ny] == 0) {
                virus_map[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }

    int safe = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (virus_map[i][j] == 0)
                safe++;

    result = max(result, safe);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> lab[i][j];

    // 벽 3개를 세울 모든 조합 시도
    for (int i = 0; i < N * M; i++) {
        int x1 = i / M, y1 = i % M;
        if (lab[x1][y1] != 0) continue;
        lab[x1][y1] = 1;

        for (int j = i + 1; j < N * M; j++) {
            int x2 = j / M, y2 = j % M;
            if (lab[x2][y2] != 0) continue;
            lab[x2][y2] = 1;

            for (int k = j + 1; k < N * M; k++) {
                int x3 = k / M, y3 = k % M;
                if (lab[x3][y3] != 0) continue;
                lab[x3][y3] = 1;

                copyMap(temp, lab);
                bfs(temp);

                lab[x3][y3] = 0; // 원상복구
            }
            lab[x2][y2] = 0;
        }
        lab[x1][y1] = 0;
    }

    cout << result << '\n';
    return 0;
}
