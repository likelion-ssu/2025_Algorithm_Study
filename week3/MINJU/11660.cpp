#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,M; // 표의 크기, 합을 구해야 하는 횟수
int x1,y1,x2,y2;
int dp[1025][1025]= {0,};

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    cin >> N >> M;
    int table[N+1][N+1];

    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            cin >> table[i][j];
            dp[i][j]= table[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
             // 내 위 원소 dp 값 + 왼쪽 원소 dp 값 - 왼쪽위원소 dp 값 (중복 범위)
        }
    }

    for (int i=0; i<M; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1] << "\n";
        // 합을 구해 출력
    }

   return 0;
}