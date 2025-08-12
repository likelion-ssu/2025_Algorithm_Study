#include <iostream>
using namespace std;

int a[1025][1025];
int cum_sum[1025][1025]; // 누적된 합을 저장하는 배열

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  // 표 입력
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> a[i][j];
    }
  }

  // 누적합 배열 만들기
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cum_sum[i][j] = a[i][j] + cum_sum[i - 1][j] + cum_sum[i][j - 1] - cum_sum[i - 1][j - 1];
    }
  }

  // 최종 결과 출력
  while (m--)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int result = cum_sum[x2][y2] - cum_sum[x1 - 1][y2] - cum_sum[x2][y1 - 1] + cum_sum[x1 - 1][y1 - 1];
    cout << result << '\n';
  }

  return 0;
}
