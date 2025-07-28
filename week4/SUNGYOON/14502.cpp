#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int lab[8][8];
int temp[8][8]; // 복사본
int dx[4] = {-1, 1, 0, 0}; // 상하
int dy[4] = {0, 0, -1, 1}; // 좌우
int maxSafe = 0;

void spreadVirus() {
    int spreadMap[8][8];
    memcpy(spreadMap, temp, sizeof(temp));  // temp 배열 복사

    queue<pair<int, int>> q;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (spreadMap[i][j] == 2)
                q.push({i, j});

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (spreadMap[nx][ny] == 0) {
                spreadMap[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }

    // 안전영역 계산
    int safeCount = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (spreadMap[i][j] == 0)
                ++safeCount;

    maxSafe = max(maxSafe, safeCount);
}

void buildWall(int count) {
    if (count == 3) {
        memcpy(temp, lab, sizeof(lab));  // 벽 3개 설치된 상태
        spreadVirus();
        return;
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (lab[i][j] == 0) {
                lab[i][j] = 1;     // 벽 설치
                buildWall(count + 1);  // 다음 벽 설치
                lab[i][j] = 0;     // 되돌리기(백트래킹)
            }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> lab[i][j];

    buildWall(0);
    cout << maxSafe << '\n';
    return 0;
}
