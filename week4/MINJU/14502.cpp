#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
const int maxNM=8;
int N,M;
int arr[maxNM][maxNM]; // 정보 저장
int tmpArr[maxNM][maxNM]; // 카운팅을 위한 임시 배열
bool visited[maxNM*maxNM]; // 방문 여부

vector<pair<int,int> >  pairVec; // 쌍을 저장
int near[2][4] = {{0,0,1,-1}, {1,-1,0,0}}; // 인접 배열

int ans=0;

void bfs(){
    queue<pair<int, int> > q; // 바이러스를 저장하는 큐

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (tmpArr[i][j]==2){
                // 바이러스가 있다면 큐에 넣음
                q.push({i,j});
            }
        }
    }

    // bfs를 사용하여 바이러스의 근원지부터 시작해서 퍼질 수 있는 곳까지 반복
    while (q.size()){
        int x= q.front().first;
        int y= q.front().second;
        q.pop();

        for (int k=0; k<4; k++){
            int nx= x+ near[0][k];
            int ny = y+near[1][k];

            if (nx>=0 && nx<N && ny>=0 && ny<M && tmpArr[nx][ny]==0){
                tmpArr[nx][ny]=2; // 바이러스가 퍼짐
                q.push({nx,ny});
            }
        }
    }

    int cnt =0;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (tmpArr[i][j]==0) {
                cnt++; // 안전구역을 카운팅
            }
        }
    }
    ans = max(ans,cnt);
}

void makeWall(int cur, int idx){
    // 3가지 벽 세울 곳을 다 골랐다면 (브루트포스)
    if (cur==3){
        memcpy(tmpArr, arr, sizeof(arr)); // 원본 배열로부터 임시로 배열을 copy해서 만듦

        int cnt= 0;
        for (int i=0; i<pairVec.size(); i++){
            if (cnt==3) break;
            if (visited[i]) {
                int x= pairVec[i].first;
                int y= pairVec[i].second;
                tmpArr[x][y]= 1; // 임시 배열에 벽을 세웠다고 가정
                cnt++;
            }
        }
        bfs(); // 안전 영역을 구하기 위해 bfs 사용
        return;
    }


    for (int i=idx; i<pairVec.size(); i++){
        if (visited[i]) continue;
        visited[i]=true;
        makeWall(cur+1, i);
        visited[i]=false;
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> arr[i][j];
            if (arr[i][j]==0)
                pairVec.push_back({i,j}); // 벽을 세울 수 있는 곳을 저장해둠
        }   
    }

    makeWall(0,0);
   
    cout << ans;

   return 0;
}