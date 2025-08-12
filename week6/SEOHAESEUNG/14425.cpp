#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_set <string> s;

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;

        s.insert(str);
    }

    int res = 0;

    for(int i = 0; i < m; i++) {
        string str;
        cin >> str;

        if(s.count(str)) {
            res++;
        } 
    }


    cout << res << "\n";

    return 0;
}