#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[8][8];
int tmp[8][8];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int answer = 0;

void bfs()
{
  int visited[8][8];
  queue<pair<int, int>> q;

  // tmp 복사해서 visited 만들고 바이러스 넣기
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      visited[i][j] = tmp[i][j];
      if (visited[i][j] == 2)
      {
        q.push({i, j});
      }
    }
  }

  // 바이러스 퍼뜨리기
  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && ny >= 0 && nx < n && ny < m)
      {
        if (visited[nx][ny] == 0)
        {
          visited[nx][ny] = 2;
          q.push({nx, ny});
        }
      }
    }
  }

  // 안전 영역 세기
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (visited[i][j] == 0)
        count++;
    }
  }
  answer = max(answer, count);
}

// 벽 3개 세우기 (DFS 방식)
void wall(int count)
{
  if (count == 3)
  {
    // 원본 map -> tmp 복사
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        tmp[i][j] = map[i][j];
      }
    }
    bfs(); // 벽 다 세웠으면 바이러스 퍼뜨리기
    return;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (map[i][j] == 0)
      {
        map[i][j] = 1;
        wall(count + 1);
        map[i][j] = 0;
      }
    }
  }
}

int main()
{
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
    }
  }

  wall(0);
  cout << answer << '\n';
  return 0;
}
