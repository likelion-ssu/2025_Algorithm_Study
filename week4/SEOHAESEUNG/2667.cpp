#include <bits/stdc++.h>
using namespace std;

int city[30][30];
int n;

int bfs(int row, int column) {
    int num = 0;
    queue <pair <int, int>> q;
    q.push({row, column});

    city[row][column] = 0;

    while(!q.empty()) {
        num++;
        pair <int, int> tmp;
        tmp = q.front();

        if(city[tmp.first - 1][tmp.second] > 0) {
            q.push({tmp.first - 1, tmp.second});
            city[tmp.first - 1][tmp.second] = 0;
        }
        if(city[tmp.first + 1][tmp.second] > 0) {
            q.push({tmp.first + 1, tmp.second});
            city[tmp.first + 1][tmp.second] = 0;
        }
        if(city[tmp.first][tmp.second - 1] > 0) {
            q.push({tmp.first, tmp.second - 1});
            city[tmp.first][tmp.second - 1] = 0;
        }
        if(city[tmp.first][tmp.second + 1] > 0) {
            q.push({tmp.first, tmp.second + 1});
            city[tmp.first][tmp.second + 1] = 0;
        }
    

        q.pop();
    }

    return num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < s.length(); j++) {
            city[i][j + 1] = s[j] - '0';
        }
    }

    int total = 0;
    vector <int> res;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(city[i][j] < 1) continue;
            int a = bfs(i, j);
            if(a > 0) {
                total++;
                res.push_back(a);
            }
        }
    }

    sort(res.begin(), res.end());

    cout << total << "\n";
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }

    return 0;
}