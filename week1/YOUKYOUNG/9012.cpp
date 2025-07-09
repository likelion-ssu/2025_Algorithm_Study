#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkBracket(string cmd)
{
  stack<char> s;

  for (int j = 0; j < cmd.length(); j++)
  {
    char ch = cmd[j];
    if (ch == '(')
    {
      s.push(ch);
    }
    else if (ch == ')')
    {
      if (s.empty())
        return false;
      char openCh = s.top();
      s.pop();
      if (ch == ')' && openCh != '(')
        return false;
    }
  }
  return s.empty();
}

int main()
{
  // 입출력 성능 높임
  ios::sync_with_stdio(false); // C의 stdio를 비동기화해 입출력 속도 증가시킴
  cin.tie(NULL);

  int n;
  string cmd;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> cmd;
    if (checkBracket(cmd))
      cout << "YES" << "\n";
    else
      cout << "NO" << "\n";
  }
  return 0;
}