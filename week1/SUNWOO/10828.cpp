#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    stack<int> s;

    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int x;
            cin >> x;
            s.push(x);
        }
        else if (cmd == "pop") {
            if (s.empty()) cout << -1 << '\n';
            else {
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else if (cmd == "size") {
            cout << s.size() << '\n';
        }
        else if (cmd == "empty") {
            cout << s.empty() << '\n';
        }
        else if (cmd == "top") {
            cout << (s.empty() ? -1 : s.top()) << '\n';
        }
    }

    return 0;
}
