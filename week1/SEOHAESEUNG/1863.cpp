#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    stack <int> sky_line;
    int highest = 0;
    int res = 0;

    cin >> n;


    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if(sky_line.empty()) {
            highest = y;
            sky_line.push(y);
            continue;
        }
        if(sky_line.top() < y) {
            highest = y;
            sky_line.push(y);
            continue;
        }
        while(!sky_line.empty() && sky_line.top() > y) {
            sky_line.pop();
            res++;
        }
        if(!sky_line.empty() && sky_line.top() == y) {
            continue;
        }
        sky_line.push(y);
    }

    while(!sky_line.empty() && sky_line.top() > 0) {
        sky_line.pop();
        res++;
    }

    cout << res << "\n";

    return 0;
}