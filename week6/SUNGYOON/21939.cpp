#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    set<pair<int,int>> problems; // (난이도, 문제번호)
    unordered_map<int,int> level; // 문제번호 -> 난이도

    for (int i = 0; i < N; ++i) {
        int P, L;
        cin >> P >> L;
        problems.insert({L, P});
        level[P] = L;
    }

    int M;
    cin >> M;

    while (M--) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int P, L;
            cin >> P >> L;
            problems.insert({L, P});
            level[P] = L;
        }
        else if (cmd == "solved") {
            int P;
            cin >> P;
            problems.erase({level[P], P});
            level.erase(P);
        }
        else if (cmd == "recommend") {
            int x;
            cin >> x;
            if (x == 1) {
                auto hardest = problems.rbegin();
                cout << hardest->second << "\n";
            } else {
                auto easiest = problems.begin();
                cout << easiest->second << "\n";
            }
        }
    }
    return 0;
}
