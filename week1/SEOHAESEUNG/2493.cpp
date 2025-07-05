#include <bits/stdc++.h>

using namespace std;

int res[500500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    stack<pair<int, int>> line;

    for(int i = 0; i < n; i++) {
        pair<int, int> p;
        cin >> p.first;
        p.second = i + 1;
        
        if(line.size() == 0) {
            line.push(p);
            res[i] = 0;
            continue;
        }

        while(line.size() > 0 && line.top().first < p.first) {
            line.pop();
        }
        if(line.size() < 1) {
            line.push(p);
            res[i] = 0;
            continue;
        }

        res[i] = line.top().second;
        line.push(p);
    }

    for(int i = 0; i < n; i++) {
        
        cout << res[i] << " ";
    }

    return 0;
}