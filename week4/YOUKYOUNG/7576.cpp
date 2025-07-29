#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int m, n;
int box[1000][1000];
int day[1000][1000];
int dx[4] = {0, 0, -1, 1}; // 좌우상하
int dy[4] = {-1, 1, 0, 0};

int main()
{
  cin >> m >> n; // m:가로, n:세로
  queue<pair<int, int>> q;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> box[i][j];
      if (box[i][j] == 1)
      {
        q.push({i, j}); // 익은 토마토는 BFS 시작점
      }
    }
  }

  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      // 범위 안에 있고, 안 익은 토마토일 때
      if (nx >= 0 && ny >= 0 && nx < n && ny < m)
      {
        if (box[nx][ny] == 0)
        {
          box[nx][ny] = 1;             // 익게 만들고
          day[nx][ny] = day[x][y] + 1; // 날짜 저장
          q.push({nx, ny});
        }
      }
    }
  }

  int result = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      // 아직 안 익은 토마토가 있으면
      if (box[i][j] == 0)
      {
        cout << -1 << '\n';
        return 0;
      }
      result = max(result, day[i][j]);
    }
  }

  cout << result << '\n';
  return 0;
}
