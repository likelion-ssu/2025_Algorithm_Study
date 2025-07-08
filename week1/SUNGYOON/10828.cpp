#include <iostream>
#include <stack>
using namespace std;

int N, x;
string s;
stack<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s;

        if (s == "push") {
            cin >> x;
            st.push(x);
        }
        else if (s == "pop") {
            if (!st.empty()) {
                cout << st.top() << '\n';
                st.pop();
            } else {
                cout << -1 << '\n';
            }
        }
        else if (s == "size") {
            cout << st.size() << '\n';
        }
        else if (s == "empty") {
            cout << (st.empty() ? 1 : 0) << '\n';
        }
        else if (s == "top") {
            if (!st.empty()) {
                cout << st.top() << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}
