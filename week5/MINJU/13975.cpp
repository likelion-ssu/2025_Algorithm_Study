#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
long long T,K;

long long file(){
   priority_queue<long long, vector<long long>, greater<long long>> pq;
   long long ans =0;
   long long tmp, A, B;

   cin >> K;
   for (int i=0; i<K; i++){
      cin >> tmp;
      pq.push(tmp);
   }
   
   while (pq.size()>1){
      A = pq.top(); pq.pop();
      B = pq.top(); pq.pop();
      ans+=A+B;
      pq.push(A+B);
   }
   return ans;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> T;
   for (int i=0; i<T; i++){
      cout << file() << endl;
   }
    
   return 0;
}