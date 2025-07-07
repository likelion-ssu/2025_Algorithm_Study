// boj 10866: 덱
#include <iostream>
#include <deque>

using namespace std;

int main() {

    int N, X;
    string S;
    deque<int> d;

    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> S;

        // 1. push_front X
        if (S == "push_front") {
            cin >> X;
            d.push_front(X);
        }
        // 2. push_back X
        else if (S == "push_back") {
            cin >> X;
            d.push_back(X);
        }
        // 3. pop_front
        else if (S == "pop_front")
            // 덱이 비어있지 않는 경우
            if (!d.empty()) {
                cout << d.front() << "\n";
                d.pop_front();
            // 덱이 비어 있는 경우 -1 출력
            } 
            else {
                cout << -1 << "\n";
            }
        // 4. pop_back
        else if (S == "pop_back")
            // 덱이 비어있지 않는 경ㅇ 
            if (!d.empty()) {
                cout << d.back() << "\n";
                d.pop_back();
            } 
            // 덱이 비어있는 경우 -1 출력
            else {
                cout << -1 << "\n";
            }
        // 5. size
        else if (S == "size") {
            cout << d.size() << "\n";
        }
        // 6. empty
        else if (S == "empty") {
            // cout << q.empty() << "\n";
            cout << (d.empty() ? 1 : 0) << "\n"; // 출력 명확히
        }
        // 7. front
        else if (S == "front") {
            if (!d.empty()) {
                cout << d.front() << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
        // 8. back
        else if (S == "back") {
            if (!d.empty()) {
                cout << d.back() << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }
    
    return 0;
}