#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int T, M, tmp;
multiset<int> leftSet, rightSet;

// set의 균형을 유지하기 위해 필요한 함수
void rebalance(){
   // left의 크기가 너무 크면
   if (leftSet.size() > rightSet.size()+1){
      auto it = prev(leftSet.end()); 
      rightSet.insert(*it); // 값을 넣고
      leftSet.erase(it); // 지운다
   } 
   // right가 더 크면
   else if (rightSet.size() > leftSet.size()) {
       auto it = rightSet.begin();
        leftSet.insert(*it); // 값을 넣고
        rightSet.erase(it); // 지운다
   }
}

// 알맞은 set을 선택하여 숫자를 삽입
void insertNum(int num){
   if (leftSet.empty() || num <= *leftSet.rbegin())
      leftSet.insert(num); // 
   else 
      rightSet.insert(num);
   rebalance();
}

int getMedian(){
   return *leftSet.rbegin();
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> T;
   
   while (T--){
      leftSet.clear(); rightSet.clear();
      cin >> M;
      if (M%2==0) cout << M/2 << "\n";
      else cout << M/2+1 << "\n"; 

      for (int i=0; i<M; i++){
         cin >> tmp;
         insertNum(tmp);

         if (i%2==0){
            // 홀수 읽을 때마다 중앙값 출력
            cout << getMedian() << " ";
         }
      }
      cout << "\n";
   }

   return 0;
}