#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> grid;
bool visited[25][25];
int dx[] = {0, 1, 0, -1}; // 우, 하, 좌, 상
int dy[] = {1, 0, -1, 0};

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int count = 1;

    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N &&
                !visited[nx][ny] && grid[nx][ny] == '1') {
                visited[nx][ny] = true;
                q.push({nx, ny});
                count++;
            }
        }
    }
    return count;
}

int main() {
    cin >> N;
    grid.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    vector<int> result;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (!visited[i][j] && grid[i][j] == '1')
                result.push_back(bfs(i, j));

    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (int cnt : result) cout << cnt << '\n';

    return 0;
}
