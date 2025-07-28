#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N;
vector<vector<int>> box;
queue<pair<int, int>> q;

int dx[4] = {-1, 1, 0, 0}; // 상하좌우
int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;
    box.resize(N, vector<int>(M));

    // 익은 토마토 좌표를 큐에 저장
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    // BFS 
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // 범위를 벗어나거나, 익었거나, 비어있으면 무시
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (box[nx][ny] != 0) continue;

            box[nx][ny] = box[x][y] + 1; // 날짜 + 1
            q.push({nx, ny});
        }
    }

    int maxDay = 0;

    // 모든 토마토 확인
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (box[i][j] == 0) {
                cout << -1 << '\n';
                return 0; // 모두 익지는 못하는 상황
            }
            maxDay = max(maxDay, box[i][j]);
        }
    }

    cout << maxDay - 1 << '\n'; // 출력 시, 시작일이 1이므로 -1
    return 0;
}
