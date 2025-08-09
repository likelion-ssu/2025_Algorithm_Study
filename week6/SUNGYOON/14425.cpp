#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    unordered_set<string> S;
    S.reserve(N);

    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        S.insert(str);
    }

    int ans = 0;
    for (int i = 0; i < M; ++i) {
        string q;
        cin >> q;
        if (S.find(q) != S.end()) ++ans;
    }

    cout << ans << '\n';
    return 0;
}
