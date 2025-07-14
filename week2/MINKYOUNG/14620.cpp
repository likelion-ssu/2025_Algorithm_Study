// boj: 14620: 꽃길
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
int board[11][11]; // 화단 가격 저장하려고 
vector<int> seeds; // 가능한 중앙 위치 (가장자리 제외)
vector<int> selected; // 현재 선택된 꽃 중앙 좌표 index (3개)
int minCost = 1e9;

int dx[4] = {0, 0, 1, -1}; // 동서남북
int dy[4] = {1, -1, 0, 0};

// 3개의 꽃 위치 조합만드는 함수 
void combination(int start) {
    if (selected.size() == 3) {
        set<pair<int, int>> flowerArea;
        int cost = 0;

        for (int idx : selected) {
            int r = idx / n;
            int c = idx % n;

            vector<pair<int, int>> parts = {{r, c}};
            for (int dir = 0; dir < 4; dir++) {
                int nr = r + dy[dir];
                int nc = c + dx[dir];
                parts.emplace_back(nr, nc);
            }
            
            // 예외 처리 추가
            // 겹치는 칸이 있는 경우 제외
            for (auto& p : parts) {
                if (flowerArea.count(p)) return;
                flowerArea.insert(p);
                cost += board[p.first][p.second];
            }
        }

        // 15칸 모두 겹치지 않고 구성 -> 최소값 갱신
        if (flowerArea.size() == 15)
            minCost = min(minCost, cost);

        return;
    }

    // 조합으로 3개 선택
    for (int i = start; i < seeds.size(); i++) {
        selected.push_back(seeds[i]);
        combination(i + 1);
        selected.pop_back();
    }
}

int main() {
    cin >> n;

    // 화단 입력받음
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    // 가능한 꽃 중심 좌표 인덱스 저장 (가장자리 제외)
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            seeds.push_back(i * n + j); // 1차원으로 입력 
        }
    }

    combination(0);

    cout << minCost << '\n';
}


// 각 꽃은 5개의 칸을 차지 (가운데 + 4방향)
// 총 3개의 꽃을 심어야 하며, 서로 겹치지 않아야 하고, 화단을 벗어나면 안 됨.
// 각 칸마다 가격이 있고, 총 15칸의 가격 합이 최소가 되도록 꽃 3개를 심는 조합을 찾아야 함

// 중앙 좌표 선택 가능한 개수: (N - 2)² ≤ 64
// 64개 중 3개 선택: 최대 41,664개 조합
// 각 조합마다 최대 15칸 확인 → 완전탐색 가능 (N <= 10)