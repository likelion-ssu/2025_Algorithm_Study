#include <iostream>
#include <queue>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T; // 테스트 케이스 수

  while (T--)
  {
    int K;
    cin >> K; // 파일 개수

    priority_queue<long long, vector<long long>, greater<long long>> q;

    for (int i = 0; i < K; i++)
    {
      long long x;
      cin >> x;
      q.push(x); // 우선순위 큐에 삽입
    }

    long long result = 0;

    while (q.size() > 1)
    {
      long long a = q.top();
      q.pop();
      long long b = q.top();
      q.pop();

      long long sum = a + b;
      result += sum;
      q.push(sum); // 합친 파일 다시 큐에 삽입
    }

    cout << result << '\n';
  }

  return 0;
}
