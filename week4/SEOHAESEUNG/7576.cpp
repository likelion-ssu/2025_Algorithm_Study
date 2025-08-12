#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1010][1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    bool all_tomato_complete = true;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
        cin >> arr[i][j];
    }

    queue <pair <int, int>> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0) {
                all_tomato_complete = false;
            }
            else if(arr[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    if(all_tomato_complete) {
        cout << "0\n";
        return 0;
    }

    while(!q.empty()) {
        pair <int, int> tmp = q.front();
        int day = arr[tmp.first][tmp.second];

        if(tmp.first > 0 && arr[tmp.first - 1][tmp.second] == 0) {
            q.push({tmp.first - 1, tmp.second});
            arr[tmp.first - 1][tmp.second] = day + 1;
        }
        if(tmp.first < n - 1 && arr[tmp.first + 1][tmp.second] == 0) {
            q.push({tmp.first + 1, tmp.second});
            arr[tmp.first + 1][tmp.second] = day + 1;
        }
        if(tmp.second > 0 && arr[tmp.first][tmp.second - 1] == 0) {
            q.push({tmp.first, tmp.second - 1});
            arr[tmp.first][tmp.second - 1] = day + 1;
        }
        if(tmp.second < m - 1 && arr[tmp.first][tmp.second + 1] == 0) {
            q.push({tmp.first, tmp.second + 1});
            arr[tmp.first][tmp.second + 1] = day + 1;
        }

        q.pop();
    }

    int best = 0;
    bool is_not_complete = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            best = max(best, arr[i][j]);
            if(arr[i][j] == 0) is_not_complete = true;
        }
    }

    // Debug
    /*
    cout << "\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    */

    if(is_not_complete) {
        cout << "-1\n";
        return 0;
    }
    else {
        cout << best - 1 << "\n";
    }

    return 0;
}