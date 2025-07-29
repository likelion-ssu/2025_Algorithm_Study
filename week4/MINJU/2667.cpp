#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

char c;
const int V = 27; // 25 + 여유 공간 2
int N, cnt; // 5~25

int adj[V][V]; // 0으로 초기화된 전역 배열
int near[2][4] = {{0,0,1,-1}, {1,-1,0,0}};
vector<int> ans;

void dfs(int x, int y){
    cnt++;
    adj[x][y]=0;

    for (int i=0; i<4; i++){
       if (adj[x+near[0][i]][y+near[1][i]]) {
            dfs(x+near[0][i], y+near[1][i]);
       }
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> N;

   for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
        cin >> c;
        adj[i+1][j+1]= c-'0'; // 0행, 0열은 사용하지 않음
    }
   }

   for (int i=1; i<=N; i++){
    for (int j=1; j<=N; j++){
        if (adj[i][j]) {
            cnt=0;
            dfs(i,j);
            ans.push_back(cnt);
        }
    }
   }

   cout << ans.size() << "\n";
   sort(ans.begin(), ans.end());
   for (int i=0; i<ans.size(); i++){
    cout << ans[i] << "\n";
   }

   return 0;
}