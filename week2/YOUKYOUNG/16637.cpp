#include <iostream>
#include <string>
#include <climits>
using namespace std;

int n;
string str;
int answer = INT_MIN;

int calc(int a, char op, int b)
{
  if (op == '+')
    return a + b;
  if (op == '-')
    return a - b;
  if (op == '*')
    return a * b;
  return 0;
}

void dfs(int index, int now)
{
  // 식 끝
  if (index >= n)
  {
    if (now > answer)
      answer = now;
    return;
  }

  // 1. 괄호 없이 계산
  char op = str[index - 1];   // 연산자 위치
  int num = str[index] - '0'; // 연산할 오른쪽 숫자
  dfs(index + 2, calc(now, op, num));

  // 2. 괄호 추가해서 먼저 계산
  if (index + 2 < n)
  {
    int bracket = calc(str[index] - '0', str[index + 1], str[index + 2] - '0');
    dfs(index + 4, calc(now, op, bracket)); // bracket에서 먼저 계산하고 calc에 삽입
  }
}

int main()
{
  cin >> n >> str;

  dfs(2, str[0] - '0');
  cout << answer << '\n';

  return 0;
}
