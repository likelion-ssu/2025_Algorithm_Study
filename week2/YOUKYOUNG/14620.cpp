#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int arr[10][10];
bool check[10][10];
int answer = INT_MAX;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// 꽃을 심을 수 있는지 확인
bool canPlace(int x, int y)
{
  if (check[x][y]) // 중심이 이미 사용됨
    return false;

  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    // 격자 밖으로 나가거나, 이미 사용된 칸이면 false
    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
      return false;
    if (check[nx][ny])
      return false;
  }

  return true;
}

// 꽃을 심고 비용 계산
int putFlower(int x, int y)
{
  int cost = arr[x][y];
  check[x][y] = true;

  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    check[nx][ny] = true;
    cost += arr[nx][ny];
  }

  return cost;
}

// 꽃 제거 (백트래킹)
void removeFlower(int x, int y)
{
  check[x][y] = false;

  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    check[nx][ny] = false;
  }
}

void solve(int count, int sum)
{
  // 꽃 3개 다 심었으면 최소값 갱신
  if (count == 3)
  {
    answer = min(answer, sum);
    return;
  }

  // 꽃 중심은 (1,1) ~ (n-2,n-2)만 가능함
  for (int i = 1; i < n - 1; i++)
  {
    for (int j = 1; j < n - 1; j++)
    {
      if (canPlace(i, j))
      {
        int cost = putFlower(i, j);   // 꽃 심기
        solve(count + 1, sum + cost); // 다음 꽃 심기(재귀)
        removeFlower(i, j);           // 백트래킹(꽃 제거)
      }
    }
  }
}

int main()
{
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
    }
  }

  solve(0, 0);
  cout << answer << endl;

  return 0;
}