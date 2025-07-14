// boj: 16439: 치킨치킨치킨
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int map[31][31]; // 회원/치킨
int maxPrefer = 0; // 최댓값

int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) 
            cin >> map[i][j]; // 수 저장
    }

    // 치킨 3종류 조합
    for (int i=0; i<M; i++) {
        for (int j=i+1; j<M; j++) {
            for (int k=j+1; k<M; k++) {
                int total = 0; // 항목별 최댓값을 저장할 곳 초기화
                for (int p = 0; p<N; p++) { // p는 사람 수를 의미함
                    // 각 사람마다 선택한 치킨 3가지 중 최대 값 선택
                    int best = max({map[p][i], map[p][j], map[p][k]});
                    total += best; // 각 항목별 최댓값 더함
                } 
                // 코드 추가 -> 더 큰 값을 비교하는 로직 필요
                maxPrefer = max(maxPrefer, total); 
            }
        }
    }

    cout << maxPrefer << "\n";

    return 0;
}