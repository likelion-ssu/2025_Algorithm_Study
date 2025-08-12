#include <bits/stdc++.h>
using namespace std;

int N;
int board[11][11];
bool visited[11][11];
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};
int answer = 1e9;

bool isAvailable(int x, int y) {
    for (int i = 0; i < 5; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (visited[nx][ny] || nx < 0 || ny < 0 || nx >= N || ny >= N)
            return false;
    }
    return true;
}

int plant(int x, int y) {
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        visited[nx][ny] = true;
        sum += board[nx][ny];
    }
    return sum;
}

void unplant(int x, int y) {
    for (int i = 0; i < 5; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        visited[nx][ny] = false;
    }
}

void dfs(int cnt, int sum) {
    if (cnt == 3) {
        answer = min(answer, sum);
        return;
    }
    for (int i = 1; i < N - 1; ++i) {
        for (int j = 1; j < N - 1; ++j) {
            if (isAvailable(i, j)) {
                int cost = plant(i, j);
                dfs(cnt + 1, sum + cost);
                unplant(i, j);
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
    dfs(0, 0);
    cout << answer;
    return 0;
}