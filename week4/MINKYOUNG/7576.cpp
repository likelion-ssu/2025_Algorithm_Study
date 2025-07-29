// boj 7576: 토마토
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N;
int box[1000][1000];
int days[1000][1000];
int dx[4] = {0, 0, -1, 1}; 
int dy[4] = {-1, 1, 0, 0};

queue<pair<int, int>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                q.push({i, j});
                days[i][j] = 0;
            } else {
                days[i][j] = -1; // 아직 방문 안 함
            }
        }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;

            if (box[nx][ny] == 0 && days[nx][ny] == -1) {
                days[nx][ny] = days[x][y] + 1;
                box[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    int max_day = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            if (box[i][j] == 0) {
                cout << -1 << '\n';
                return 0;
            }
            if (days[i][j] > max_day)
                max_day = days[i][j];
        }

    cout << max_day << '\n';
    return 0;
}
