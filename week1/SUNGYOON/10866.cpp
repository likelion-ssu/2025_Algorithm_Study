#include <iostream>
#include <deque>
using namespace std;

int N, x;
string s;
deque<int> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s;

        if (s == "push_front") {
            cin >> x;
            dq.push_front(x);
        }
        else if (s == "push_back") {
            cin >> x;
            dq.push_back(x);
        }
        else if (s == "pop_front") {
            if (!dq.empty()) {
                cout << dq.front() << '\n';
                dq.pop_front();
            } else {
                cout << -1 << '\n';
            }
        }
        else if (s == "pop_back") {
            if (!dq.empty()) {
                cout << dq.back() << '\n';
                dq.pop_back();
            } else {
                cout << -1 << '\n';
            }
        }
        else if (s == "size") {
            cout << dq.size() << '\n';
        }
        else if (s == "empty") {
            cout << (dq.empty() ? 1 : 0) << '\n';
        }
        else if (s == "front") {
            if (!dq.empty()) {
                cout << dq.front() << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
        else if (s == "back") {
            if (!dq.empty()) {
                cout << dq.back() << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}
