#include <bits/stdc++.h>
using namespace std;

int M, N;
int box[1001][1001];
int dx[] = {0, 1, 0, -1}; // 우, 하, 좌, 상
int dy[] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;
    queue<pair<int, int>> q;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            cin >> box[i][j];
            if (box[i][j] == 1)
                q.push({i, j}); // 익은 토마토부터 BFS 시작
        }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M &&
                box[nx][ny] == 0) {
                box[nx][ny] = box[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    int result = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            if (box[i][j] == 0) {
                cout << -1;
                return 0;
            }
            result = max(result, box[i][j]);
        }

    cout << result - 1; // 1부터 시작했기 때문에 -1
    return 0;
}
