// boj 18258: 큐 2
#include <iostream>
#include <queue>

using namespace std;

int main() {

    // 시간 초과 발생해 추가
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int N, X;
    string S;
    queue<int> q;

    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> S;

        // 1. push X
        if (S == "push") {
            cin >> X;
            q.push(X);
        }
        // 2. pop
        else if (S == "pop") {
            // 큐가 비어있지 않는 경우
            if (!q.empty()) {
                cout << q.front() << "\n";
                q.pop();
            }
            // 큐가 비어있는 경우 -1 출력
            else cout << -1 << "\n";
        }
        // 3. size
        else if (S == "size")
            cout << q.size() << "\n";
        // 4. empty
        else if (S == "empty")
            cout << q.empty() << "\n";
        // 5. front
        else if (S == "front") {
            // 큐가 비어있지 않는 경우
            if (!q.empty())
                cout << q.front() << "\n";
            // 큐가 비어있느 ㄴ경우 -1 출력
            else cout << -1 << "\n";
        }
        // 6. back
        else {
            // 큐가 비어있지 않는 경우
            if (!q.empty())
                cout << q.back() << "\n";
            else cout << -1 << "\n";
        }
    }

    return 0;
}

// 기본적인 큐의 STL을 활용한 구현을 했습니다.
// 특정 명령어의 경우, 큐가 비어있는 경우와 비어있지 않은 경우의 고려를 통한 구분이 필요했습니다.