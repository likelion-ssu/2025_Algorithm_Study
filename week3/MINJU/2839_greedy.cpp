#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int big=0;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   cin >> N;

    big = N/5; // 5킬로그램 봉지의 최댓값
    int leftWeight = N%5; // 5킬로그램으로 채우고 남은 무게
    while (big>=0){
        if (leftWeight%3==0){
            cout << big+(leftWeight/3);
            return 0;
        }
        big--; leftWeight+=5;
    }
   
    cout << -1;
   return 0;
}