#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int n,k, tmp;
int dp[100001]={0};

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
    vector<int> value;
   
   cin >> n >> k;
   for (int i=0; i<n; i++){
    cin >> tmp;
    value.push_back(tmp);
   }

   sort(value.begin(), value.end()); // 오름차순
   value.erase(unique(value.begin(), value.end()), value.end());
   // unique 함수: 자료구조의 맨 앞부터 유니크한 원소들로만 채우고, end 위치를 반환함.

   for (int i=1; i<=k; i++) dp[i]= INT_MAX; // 최댓값으로 초기화

   // 가치 합이 k가 되도록, 동전을 최소한으로 사용하여 만든다.
   // i : cost
   // j : 각 value에 접근하는 인덱스
   for (int coin: value) {
    for (int i=coin; i<=k; i++){
        if (dp[i-coin]!=INT_MAX) {
            dp[i]= min(dp[i], dp[i-coin]+1);
        }
    }
   }

   if (dp[k]==INT_MAX) cout << -1;
   else cout << dp[k];

   return 0;
}