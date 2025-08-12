#include <bits/stdc++.h>
using namespace std;

int t, m;

void f() {
    cin >> m;
    cout << m / 2 + 1 << "\n";
    int index = 1;
    priority_queue <int> left;
    priority_queue <int, vector<int>, greater<int>> right;

    int middle;
    cin >> middle;
    cout << middle << " ";


    for(int i = 1; i < m; i++) {
        int tmp;
        cin >> tmp;

        if(tmp <= middle) left.push(tmp);
        else right.push(tmp);
        if((left.size() + right.size()) % 2 != 0) continue;

        if(left.size() > right.size()) {
            right.push(middle);
            middle = left.top();
            left.pop();
        }
        else if(left.size() < right.size()) {
            left.push(middle);
            middle = right.top();
            right.pop();
        }

        cout << middle << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    for(int i = 0; i < t; i++) f();

    return 0;
}