#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int dp[5001];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N;

   // 초깃값
   dp[3]=1; 
   dp[5]=1;

   // 6kg부터 유의미함
   for (int i=6; i<=N; i++){
    if (dp[i-3]) {
        dp[i]= dp[i-3]+1; // 3kg 설탕 봉지 하나 추가
    } 
    if (dp[i-5]){
        dp[i] = dp[i-5]+1; // 5kg 설탕 봉지 하나 추가
    }
   }

   if (dp[N]) cout << dp[N];
   else cout << -1;

   return 0;
}
// dp[13]
// dp[8]=2
// 의미: dp[3]=1이고 3에서 5만큼 왔으므로 5kg짜리 봉지를 사용할 수 있다.