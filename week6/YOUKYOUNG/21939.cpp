#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  // 난이도랑 문제번호 같이 저장하는 set
  // 자동 정렬돼서 가장 어려운/쉬운 문제 찾기 편하게
  set<pair<int, int>> S;

  // 문제번호로 난이도 찾는 map
  // solved 할 때 set에서 지우려고 씀
  map<int, int> PL;

  // 처음에 주어지는 문제들 입력
  for (int i = 0; i < N; ++i)
  {
    int P, L;
    cin >> P >> L;
    S.insert({L, P}); // set에 (난이도, 문제번호) 넣기
    PL[P] = L;        // map에도 저장
  }

  int M;
  cin >> M;

  while (M--)
  {
    string cmd;
    cin >> cmd;

    if (cmd == "add")
    {
      int P, L;
      cin >> P >> L;
      S.insert({L, P}); // 새로운 문제 추가
      PL[P] = L;        // map에도 같이 넣음
    }
    else if (cmd == "solved")
    {
      int P;
      cin >> P;
      // map에서 난이도 찾고 set에서 같이 지움
      auto it = PL.find(P);
      if (it != PL.end())
      {
        S.erase({it->second, P});
        PL.erase(it);
      }
    }
    else if (cmd == "recommend")
    {
      int x;
      cin >> x;
      if (x == 1)
      {
        // 제일 어려운 문제 = set 마지막 원소
        auto it = prev(S.end());
        cout << it->second << '\n'; // 문제번호 출력
      }
      else
      {
        // 제일 쉬운 문제 = set 첫 번째 원소
        auto it = S.begin();
        cout << it->second << '\n';
      }
    }
  }
  return 0;
}
