#include <bits/stdc++.h>

using namespace std;

stack<int> s;

void s_push() {
    int n;
    cin >> n;
    s.push(n);
}

void s_pop() {
    if(s.size() == 0) {
        cout << "-1\n";
        return;
    }
    cout << s.top() << "\n";
    s.pop();
}

void s_size() {
    cout << s.size() << "\n";
}

void s_empty() {
    cout << (int)s.empty() << "\n";
}

void s_top() {
    if(s.size() == 0) {
        cout << "-1\n";
        return;
    }
    cout << s.top() << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string cmd;
    cin >> n;

    queue<int> q;

    for(int i = 0; i < n; i++) {
        cin >> cmd;
        if(cmd == "push") s_push();
        else if(cmd == "pop") s_pop();
        else if(cmd == "size") s_size();
        else if(cmd == "empty") s_empty();
        else if(cmd == "top") s_top();
    }

}