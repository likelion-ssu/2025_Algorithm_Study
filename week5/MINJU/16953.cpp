#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long A,B;
int ans=1;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    cin >> A >> B;
    
    // B가 A보다 작아지면 종료
    while (B>A){
        // 일의 자리가 1이면 10으로 나누고 나머지를 버린다.
        if (B%10==1) {
            B= B/10;
        }
        // 짝수면 2로 나눈다
        else if (B%2==0){
            B= B/2;
        } else {
            cout << -1;
            return 0;
        }
        ans++;
    }

   if (B==A) cout << ans;
   else cout << -1;

   return 0;
}