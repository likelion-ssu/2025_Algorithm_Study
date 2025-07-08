#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{

  // 입출력 성능 높임
  ios::sync_with_stdio(false); // C의 stdio를 비동기화해 입출력 속도 증가시킴
  cin.tie(NULL);

  int n, m;
  string cmd;
  queue<int> q;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> cmd;

    // 1. push
    if (cmd == "push")
    {
      cin >> m;
      q.push(m);
    }

    // 2. pop
    else if (cmd == "pop")
    {
      if (!q.empty())
      {
        cout << q.front() << "\n";
        q.pop();
      }
      // 큐가 비어있는 경우 -1 출력
      else
        cout << -1 << "\n";
    }

    // 3. size
    else if (cmd == "size")
      cout << q.size() << "\n";

    // 4. empty
    else if (cmd == "empty")
      cout << q.empty() << "\n";

    // 5. front
    else if (cmd == "front")
    {
      if (!q.empty())
        cout << q.front() << "\n";
      else
        cout << -1 << "\n";
    }
    // 6. back
    else if (cmd == "back")
    {
      if (!q.empty())
        cout << q.back() << "\n";
      else
        cout << -1 << "\n";
    }
  }

  return 0;
}