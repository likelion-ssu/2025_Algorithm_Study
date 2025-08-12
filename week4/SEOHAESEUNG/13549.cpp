#include <bits/stdc++.h>
using namespace std;

int n, k;

bool visited[200200];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    deque <pair<int, int>> d;

    d.push_back({n, 0});
    visited[n] = true;

    int res = 0;

    if(n >= k) {
        cout << n - k << "\n";
        return 0;
    }

    while(!d.empty()) {
        pair <int, int> tmp = d.front();
        d.pop_front();

        if(tmp.first == k) {
            res = tmp.second;
            break;
        }
        if(2 * tmp.first < 200000 && !visited[2 * tmp.first]) {
            visited[2 * tmp.first] = true;
            d.push_front({2 * tmp.first, tmp.second});
        }
            
        
            
        if(tmp.first > 1 && !visited[tmp.first - 1]) {
            visited[tmp.first - 1] = true;
            d.push_back({tmp.first - 1, tmp.second + 1});
        }

        if(tmp.first + 1 < 200200 && !visited[tmp.first + 1]) {
            d.push_back({tmp.first + 1, tmp.second + 1});
            visited[tmp.first + 1] = true;
        }
    }
    

    cout << res << "\n";

    return 0;
}