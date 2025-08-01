#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int tmp, posCnt=0, ans=0;
int N; 
int K; 
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

   sort(vec.begin(), vec.end());

   if (N<=K) {
      cout << 0;
      return 0;
   }

   for (int i=1; i<N; i++) space.push_back(vec[i]-vec[i-1]);
   sort(space.begin(), space.end(), greater<int>()); 
   for (int i=0; i<N-1; i++) {stck.push(space[i]); }

   while (stck.size()>K-1){
      ans+=stck.top();
      stck.pop();
   }

   cout << ans;

   return 0;
}