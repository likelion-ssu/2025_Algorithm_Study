#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int M;
        cin >> M;

        priority_queue<int> left; // 최대 힙
        priority_queue<int, vector<int>, greater<int>> right; // 최소 힙
        vector<int> medians;

        for (int i = 1; i <= M; i++) {
            int x;
            cin >> x;

            if (left.empty() || x <= left.top()) left.push(x);
            else right.push(x);

            if (left.size() > right.size() + 1) {
                right.push(left.top());
                left.pop();
            } else if (right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            }

            if (i % 2 == 1) medians.push_back(left.top());
        }

        cout << medians.size() << '\n';
        for (int i = 0; i < (int)medians.size(); i++) {
            cout << medians[i] << ' ';
            if ((i + 1) % 10 == 0) cout << '\n';
        }
        if (medians.size() % 10 != 0) cout << '\n';
    }
    return 0;
}
