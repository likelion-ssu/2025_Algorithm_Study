#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M; // N:집합 S에 포함될 문자열 개수 / M:검사할 문자열 개수
  cin >> N >> M;

  vector<string> S;
  S.reserve(N); // 메모리 미리 확보

  for (int i = 0; i < N; ++i)
  {
    string x;
    cin >> x;
    S.push_back(x);
  }

  // 이분 탐색하기 위해 정렬
  sort(S.begin(), S.end());

  int count = 0;

  for (int i = 0; i < M; ++i)
  {
    string q;
    cin >> q;

    // S 안에 q가 있으면 true
    if (binary_search(S.begin(), S.end(), q))
    {
      ++count;
    }
  }

  cout << count << '\n';

  return 0;
}
