#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 꽃길 (백트래킹)

int N;
int board[11][11];       // 화단 가격 저장
bool visited[11][11];    // 꽃이 차지한 칸 여부

// (x, y)를 중심으로 꽃을 심을 수 있는지 확인
bool canPlant(int x, int y) {
    if (visited[x][y] || visited[x - 1][y] || visited[x + 1][y] || visited[x][y - 1] || visited[x][y + 1])
        return false;
    return true;
}

// 꽃을 심고 해당 위치 5칸의 비용을 반환
int plant(int x, int y) {
    int cost = 0;
    visited[x][y] = true;           cost += board[x][y];
    visited[x - 1][y] = true;       cost += board[x - 1][y];
    visited[x + 1][y] = true;       cost += board[x + 1][y];
    visited[x][y - 1] = true;       cost += board[x][y - 1];
    visited[x][y + 1] = true;       cost += board[x][y + 1];
    return cost;
}

// 꽃 제거(백트래킹)
void remove(int x, int y) {
    visited[x][y] = false;
    visited[x - 1][y] = false;
    visited[x + 1][y] = false;
    visited[x][y - 1] = false;
    visited[x][y + 1] = false;
}

int main() {
    cin >> N;

    // 화단 가격 입력
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    int answer = INT_MAX;  // 최소 비용 초기화

    // 세 송이 꽃을 심을 위치 조합 완전탐색
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            if (!canPlant(i, j)) continue;
            int cost1 = plant(i, j);

            for (int k = 1; k < N - 1; k++) {
                for (int l = 1; l < N - 1; l++) {
                    if (!canPlant(k, l)) continue;
                    int cost2 = plant(k, l);

                    for (int m = 1; m < N - 1; m++) {
                        for (int n = 1; n < N - 1; n++) {
                            if (!canPlant(m, n)) continue;
                            int cost3 = plant(m, n);

                            // 최소 비용 갱신
                            answer = min(answer, cost1 + cost2 + cost3);

                            remove(m, n);
                        }
                    }

                    remove(k, l);
                }
            }

            remove(i, j);
        }
    }

    cout << answer << '\n';
    return 0;
}
