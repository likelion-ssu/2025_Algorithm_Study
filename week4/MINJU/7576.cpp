#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX= 1002;
int N,M;
int spent= 0;

int adj[MAX][MAX]; // 0으로 초기화된 전역배열
int near[2][4] = {{0,0,1,-1}, {1,-1,0,0}};
queue<pair<int, int>> q;

void tomato(){
    while (true){
        // 1일치 작업
        queue<pair<int,int>> newQ;
        while (!q.empty()){
            auto [qX,qY] = q.front(); q.pop();
            for (int i=0; i<4; i++){
                int intX= qX+near[0][i]; 
                int intY= qY+near[1][i];

                // 익지 않았다면
                if (intX>=1 && intX<=M && intY>=1 && intY<=N && adj[intX][intY]==0) {
                    adj[intX][intY]= 1;
                    newQ.push({intX, intY});
                }
            }
        }
        if (newQ.empty()) return; // 더이상 뻗어나갈 수 없음
        else { spent++; q=newQ; }
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> N >> M;

   for (int i=1; i<=M; i++){ // 행
    for (int j=1; j<=N; j++){ // 열
        cin >> adj[i][j];
        if (adj[i][j]==1) q.push({i,j}); // 익은 토마토는 큐에 넣어줌
        }
   }

   tomato();

   // 모든 과정을 수행하고 나서 익지 않은 토마토가 있는지 확인한다.
   for (int i=1; i<=M; i++){
    for (int j=1; j<=N; j++){
        if (adj[i][j]==0) {
            cout << -1;
            return 0;
        }
    }
   }

    // 이미 처음부터 전부 익어있었음.
   if (spent==0) cout << 0;
   else cout << spent;

   return 0;
}