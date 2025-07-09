#include <bits/stdc++.h>
using namespace std;

bool f(string a, string b) {
    if(a.length() == b.length()) {
        if(a == b) return true;
        else return false;
    }
    if(b[b.length() - 1] == 'B' && b[0] == 'A') return false;

    string case1 = b;
    string case2 = b;

    bool case1_result = false;
    bool case2_result = false;

    if(b[b.length() - 1] == 'A') {
        case1.pop_back();
        case1_result = f(a, case1);
    }
    if(b[0] == 'B') {
        case2.erase(0, 1);
        reverse(case2.begin(), case2.end());
        case2_result = f(a, case2);
    }

    if(case1_result || case2_result) return true;
    else return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string origin;
    string ans;

    cin >> origin;
    cin >> ans;

    if(f(origin, ans)) cout << "1\n";
    else cout << "0\n";

    return 0;
}