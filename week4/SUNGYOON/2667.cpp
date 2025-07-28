#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 1, 0, 0};  // 상하
int dy[4] = {0, 0, -1, 1};  // 좌우

int N;
vector<vector<int>> map;
vector<vector<bool>> visited;

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int count = 1;  // 집 수 세는 변수 선언

    while (!q.empty()) {
        auto [curX, curY] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];

            // 범위 초과, 방문했거나, 집이 아닌 경우에 무시
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (visited[nx][ny] || map[nx][ny] == 0) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
            count++;
        }
    }

    return count;
}

int main() {
    cin >> N;
    map.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));

    // 지도 입력
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            map[i][j] = row[j] - '0';
        }
    }

    vector<int> houseCounts;  // 저장 역할

    // BFS 실행
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                houseCounts.push_back(bfs(i, j));
            }
        }
    }

    sort(houseCounts.begin(), houseCounts.end());

    cout << houseCounts.size() << '\n';  // 단지 수 출력
    for (int count : houseCounts) {
        cout << count << '\n';            // 각 단지 집 수 출력
    }

    return 0;
}
