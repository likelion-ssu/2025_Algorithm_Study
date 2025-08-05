#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int tmp, posCnt=0, ans=0;
int N; // 센서 개수
int K; // 최대 세울 수 있는 집중국 개수
// (시그마) 집중국의 수신가능영역의 최소를 구해야 됨
vector<int> vec;
vector<int> space;
stack<int> stck;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> N >> K;
   
   for (int i=0; i<N; i++){
      cin >> tmp;
      vec.push_back(tmp);
   }

   sort(vec.begin(), vec.end()); // 오름차순 정렬

   // 바로 센서 위치마다 기지국 세울 수 있음
   if (N<=K) {
      cout << 0;
      return 0;
   }

   for (int i=1; i<N; i++) space.push_back(vec[i]-vec[i-1]);
   sort(space.begin(), space.end(), greater<int>()); // 내림차순
   for (int i=0; i<N-1; i++) {stck.push(space[i]); }// 차가 작은 게 맨 위에

   while (stck.size()>K-1){
      ans+=stck.top();
      stck.pop();
   }

   cout << ans;

   return 0;
}