#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    deque<int> dq;

    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "push_front") {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if (cmd == "push_back") {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if (cmd == "pop_front") {
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (cmd == "pop_back") {
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (cmd == "size") {
            cout << dq.size() << '\n';
        }
        else if (cmd == "empty") {
            cout << dq.empty() << '\n';
        }
        else if (cmd == "front") {
            cout << (dq.empty() ? -1 : dq.front()) << '\n';
        }
        else if (cmd == "back") {
            cout << (dq.empty() ? -1 : dq.back()) << '\n';
        }
    }

    return 0;
}
