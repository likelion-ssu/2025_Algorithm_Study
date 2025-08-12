#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;

  // arr[i]는 i킬로그램을 만들기 위한 봉지 수
  int arr[5001];

  // 5001로 초기화(불가능)
  for (int i = 0; i <= n; i++)
  {
    arr[i] = 5001;
  }

  arr[0] = 0;

  for (int i = 3; i <= n; i++)
  {
    // 3kg 봉지
    if (i >= 3)
      arr[i] = min(arr[i], arr[i - 3] + 1);
    // 5kg 봉지
    if (i >= 5)
      arr[i] = min(arr[i], arr[i - 5] + 1);
  }

  if (arr[n] == 5001)
  {
    cout << -1 << "\n"; // 정확히 만들 수 없는 경우
  }
  else
  {
    cout << arr[n] << "\n";
  }

  return 0;
}
