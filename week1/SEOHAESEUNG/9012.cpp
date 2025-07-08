#include <bits/stdc++.h>

using namespace std;

bool f(string str) {
    stack<char> s;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(')
            s.push('(');
        else if(str[i] == ')') {
            if(s.size() < 1 || s.top() != '(') return false;
            s.pop();
        }
    }

    if(s.size() != 0) return false;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> s;
        if(f(s)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}