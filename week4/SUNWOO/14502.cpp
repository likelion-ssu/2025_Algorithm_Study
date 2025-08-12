#include <bits/stdc++.h>
using namespace std;

int N, M;
int lab[8][8], copyLab[8][8];
int dx[] = {0, 1, 0, -1}; // 4방향
int dy[] = {1, 0, -1, 0};
int maxSafe = 0;

void spreadVirus() {
    queue<pair<int, int>> q;

    // copy에서 바이러스 위치 push
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (copyLab[i][j] == 2)
                q.push({i, j});

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M &&
                copyLab[nx][ny] == 0) {
                copyLab[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
}

int countSafe() {
    int cnt = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (copyLab[i][j] == 0)
                cnt++;
    return cnt;
}

void setWall(int cnt) {
    if (cnt == 3) {
        // 복사하고 확산
        memcpy(copyLab, lab, sizeof(lab));
        spreadVirus();
        maxSafe = max(maxSafe, countSafe());
        return;
    }

    // 벽 세우기 (조합 방식)
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (lab[i][j] == 0) {
                lab[i][j] = 1;
                setWall(cnt + 1);
                lab[i][j] = 0;
            }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> lab[i][j];

    setWall(0);
    cout << maxSafe;
    return 0;
}
