#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[25][25];
bool visited[25][25];
int dx[4] = {0, 0, -1, 1}; // 좌우상하
int dy[4] = {-1, 1, 0, 0};

int dfs(int x, int y)
{
  visited[x][y] = true;
  int count = 1;

  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx >= 0 && ny >= 0 && nx < n && ny < n)
    {
      if (map[nx][ny] == 1 && !visited[nx][ny])
      {
        count += dfs(nx, ny);
      }
    }
  }

  return count;
}

int main()
{
  cin >> n;
  vector<int> a;

  // 지도 입력받기
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++)
    {
      map[i][j] = s[j] - '0';
    }
  }

  // 전체 지도 돌면서 dfs 실행
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (map[i][j] == 1 && !visited[i][j])
      {
        int res = dfs(i, j);
        a.push_back(res);
      }
    }
  }
  sort(a.begin(), a.end());

  cout << a.size() << '\n';
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << '\n';
  }

  return 0;
}
