#include <bits/stdc++.h>
using namespace std;

int n, m;
int prefer[31][31];
int answer = 0;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> prefer[i][j];

    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            for (int k = j + 1; k < m; ++k) {
                int sum = 0;
                for (int t = 0; t < n; ++t) {
                    int maxPref = max({prefer[t][i], prefer[t][j], prefer[t][k]});
                    sum += maxPref;
                }
                answer = max(answer, sum);
            }
        }
    }
    cout << answer;
    return 0;
}
