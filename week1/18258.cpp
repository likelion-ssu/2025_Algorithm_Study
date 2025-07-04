#include <bits/stdc++.h>

using namespace std;

queue<int> q;

void q_push() {
    int n;
    cin >> n;
    q.push(n);
}

void q_pop() {
    if(q.size() == 0) {
        cout << "-1\n";
        return;
    }
    cout << q.front() << "\n";
    q.pop();
}

void q_size() {
    cout << q.size() << "\n";
}

void q_empty() {
    cout << (int)q.empty() << "\n";
}

void q_front() {
    if(q.size() == 0)
    cout << "-1\n";
    else
    cout << q.front() << "\n";
}

void q_back() {
    if(q.size() == 0)
    cout << "-1\n";
    else
    cout << q.back() << "\n";
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
        if(cmd == "push") q_push();
        else if(cmd == "pop") q_pop();
        else if(cmd == "size") q_size();
        else if(cmd == "empty") q_empty();
        else if(cmd == "front") q_front();
        else if(cmd == "back") q_back();
    }

}