#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// leftHeap : 중앙값 이하 저장(최대힙)
// rightHeap : 중앙값 초과 저장(최소힙)
priority_queue<int> leftHeap;
priority_queue<int, vector<int>, greater<int>> rightHeap;

void addNumber(int x)
{
  // 왼쪽이 비었거나 x가 왼쪽의 가장 큰 값(top)보다 작으면 왼쪽에 push
  if (leftHeap.empty() || x <= leftHeap.top())
    leftHeap.push(x);
  else
    rightHeap.push(x);

  // 크기 맞추는 코드
  if (leftHeap.size() < rightHeap.size())
  {
    leftHeap.push(rightHeap.top());
    rightHeap.pop();
  }
  // 왼쪽이 2개 이상 많아졌으면 하나 넘겨줌
  if (leftHeap.size() > rightHeap.size() + 1)
  {
    rightHeap.push(leftHeap.top());
    leftHeap.pop();
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  while (T--)
  {
    // 새 테스트마다 힙 비우기
    while (!leftHeap.empty())
      leftHeap.pop();
    while (!rightHeap.empty())
      rightHeap.pop();

    int M;
    cin >> M;

    vector<int> med; // 홀수 번째마다 중앙값 저장

    for (int i = 1; i <= M; i++)
    {
      int x;
      cin >> x;

      addNumber(x);

      // 홀수 개 읽었을 때만 중앙값 저장
      // (지금 규칙상 왼쪽 top이 중앙값 위치)
      if (i % 2 == 1)
      {
        med.push_back(leftHeap.top());
      }
    }

    cout << (int)med.size() << '\n';
    for (int i = 0; i < (int)med.size(); i++)
    {
      cout << med[i];
      // 10개마다 줄바꿈, 아니면 공백
      if ((i + 1) % 10 == 0 || i + 1 == (int)med.size())
        cout << '\n';
      else
        cout << ' ';
    }
  }
  return 0;
}
