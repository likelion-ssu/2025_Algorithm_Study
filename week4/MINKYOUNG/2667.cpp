// boj 2667: 단지번호 붙이기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> map;
vector<vector<bool>> visited;
int dx[4] = {-1, 1, 0, 0}; 
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y) {
    visited[x][y] = true;
    int count = 1; // 현재 집

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;

        // 연결된 집이면서 방문하지 않았드면 재귀 탐색
        if (map[nx][ny] == 1 && !visited[nx][ny]) {
            count += dfs(nx, ny);
        }
    }

    return count;
}

int main() {
    cin >> N;
    map.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++) {
            map[i][j] = line[j] - '0';
        }
    }

    vector<int> complexes;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                int houseCount = dfs(i, j);
                complexes.push_back(houseCount);
            }
        }
    }

    sort(complexes.begin(), complexes.end());

    cout << complexes.size() << '\n';
    for (int count : complexes) {
        cout << count << '\n';
    }

    return 0;
}
