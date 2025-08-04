#include <iostream>
#define MAX 10000
using namespace std;

int main()
{
  int n, k; // n : 센서 개수, k : 설치 가능한 집중국 개수
  cin >> n >> k;

  int sensor[MAX];

  for (int i = 0; i < n; i++)
  {
    cin >> sensor[i];
  }

  // 선택정렬로 센서 좌표 정렬 (오름차순)
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (sensor[i] > sensor[j])
      {
        int temp = sensor[i];
        sensor[i] = sensor[j];
        sensor[j] = temp;
      }
    }
  }

  // 예외 처리
  if (k >= n)
  {
    cout << 0 << endl;
    return 0;
  }

  // 거리 차이 배열
  int diff[MAX];

  for (int i = 0; i < n - 1; i++)
  {
    diff[i] = sensor[i + 1] - sensor[i];
  }

  // 거리 차이 배열 내림차순으로 정렬
  for (int i = 0; i < n - 2; i++)
  {
    for (int j = i + 1; j < n - 1; j++)
    {
      if (diff[i] < diff[j])
      {
        int temp = diff[i];
        diff[i] = diff[j];
        diff[j] = temp;
      }
    }
  }
  int answer = 0;

  for (int i = k - 1; i < n - 1; i++)
  {
    answer += diff[i];
  }

  cout << answer << endl;
  return 0;
}
