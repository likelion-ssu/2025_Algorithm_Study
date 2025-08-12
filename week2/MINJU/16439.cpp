#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, tmp;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> N >> M;
   int arr[31][31];

   for (int i=0; i<N; i++){
      for (int j=0; j<M; j++) cin >> arr[i][j];
   }

   // 단순 반복문 사용
   int sumMax=0;
   for (int i=0; i<M-2; i++){
      for (int j=i+1; j<M-1; j++){
         for (int w=j+1; w<M; w++){ // i, j, w: 고른 3가지 치킨
            int sum=0;
            for (int k=0; k<N; k++){
               sum+= max({arr[k][i], arr[k][j], arr[k][w]}); 
               // c++ 11부터 가능해진 방식, 참고: https://0xffffffff.tistory.com/52
            }
            if (sum>sumMax) sumMax=sum;
         }
          
      }
   }

   cout << sumMax;

   return 0;
}