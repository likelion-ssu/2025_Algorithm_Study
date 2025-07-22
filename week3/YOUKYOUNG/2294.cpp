#include <iostream>
using namespace std;

int coin[101];
int arr[10001];

int main()
{
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++)
  {
    cin >> coin[i]; // 사용 가능한 동전 종류 입력받기
  }

  // arr[i]는 i원을 만들기 위한 최소 동전 수
  for (int i = 1; i <= k; i++)
  {
    arr[i] = 10001; // 불가능한 값으로 초기화
  }
  arr[0] = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = coin[i]; j <= k; j++)
    {
      if (arr[j - coin[i]] + 1 < arr[j])
      {
        arr[j] = arr[j - coin[i]] + 1;
      }
    }
  }

  if (arr[k] == 10001)
    cout << -1 << "\n";
  else
    cout << arr[k] << "\n";

  return 0;
}
