#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
  // 입출력 성능 높임
  ios::sync_with_stdio(false); // C의 stdio를 비동기화해 입출력 속도 증가시킴
  cin.tie(NULL);

  int n, m;
  string cmd;
  stack<int> s;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> cmd;

    // 1. push
    if (cmd == "push")
    {
      cin >> m;
      s.push(m);
    }

    // 2. pop
    else if (cmd == "pop")
    {
      if (!s.empty())
      {
        cout << s.top() << "\n";
        s.pop();
      }
      // 스택이 비어있는 경우 -1 출력
      else
        cout << -1 << "\n";
    }

    // 3. size
    else if (cmd == "size")
      cout << s.size() << "\n";

    // 4. empty
    else if (cmd == "empty")
      cout << s.empty() << "\n";

    // 5. top
    else if (cmd == "top")
    {
      if (!s.empty())
        cout << s.top() << "\n";
      else
        cout << -1 << "\n";
    }
  }

  return 0;
}