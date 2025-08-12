#include <iostream>
#include <vector>
using namespace std;

int n, m;
int a[30][30]; // 만족도 저장
int answer = 0;

int main()
{
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }

  // 치킨 3종류 고르기 (i, j, k는 치킨 번호)
  for (int i = 0; i < m; i++)
  {
    for (int j = i + 1; j < m; j++)
    {
      for (int k = j + 1; k < m; k++)
      {
        int sum = 0;

        // 각 회원의 만족도 선택
        for (int x = 0; x < n; x++)
        {
          int best = 0;
          // 치킨 3종류 중 가장 만족도가 높은 값을 best에 저장
          best = max(a[x][i], max(a[x][j], a[x][k]));
          sum += best;
        }
        if (sum > answer)
          answer = sum;
      }
    }
  }

  cout << answer << '\n';
  return 0;
}
