#include <iostream>
using namespace std;

int main()
{
  long long a, b;
  cin >> a >> b;

  int count = 1;

  while (b > a)
  {
    if (b % 10 == 1)
    {
      b /= 10;
    }
    else if (b % 2 == 0)
    {
      b /= 2;
    }
    else
    {
      break; // 더 이상 거꾸로 진행 불가능
    }
    count++;
  }

  if (b == a)
  {
    cout << count << '\n';
  }
  else
  {
    cout << -1 << '\n';
  }

  return 0;
}
