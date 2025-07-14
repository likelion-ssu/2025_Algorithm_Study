#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 치킨 종류 선호도 (브루트포스) - max(만족도의 합)

int n, m;  // 회원 수, 치킨 종류 수
int pref[31][31];  // 선호도 저장: pref[i][j] = i번 회원이 j번 치킨을 선호하는 정도

int main() {
    cin >> n >> m;

    // 선호도 입력
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> pref[i][j];

    int maxTotal = 0;

    // 모든 치킨 종류 중 1~3개 조합 탐색
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            for (int k = j; k < m; k++) {
                int sum = 0;

                // 각 회원별 만족도 계산
                for (int p = 0; p < n; p++) {
                    int best = 0;
                    best = max(best, pref[p][i]);
                    best = max(best, pref[p][j]);
                    best = max(best, pref[p][k]);
                    sum += best;
                }

                maxTotal = max(maxTotal, sum);
            }
        }
    }

    cout << maxTotal << '\n';
    return 0;
}
