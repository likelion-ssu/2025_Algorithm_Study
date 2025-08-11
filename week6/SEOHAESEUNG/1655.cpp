#include <bits/stdc++.h>
using namespace std;

int n;

priority_queue <int> l;
priority_queue <int, vector<int>, greater<int>> r;
int middle;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    cin >> middle;
    cout << middle << "\n";

    if(n == 1) return 0;

    int x;
    cin >> x;

    l.push(min(x, middle));
    r.push(max(x, middle));

    cout << min(x, middle) << "\n";

    for(int i = 2; i < n; i++) {
        int tmp;
        cin >> tmp;

        if(l.size() == r.size()) {
            if(tmp > r.top()) {
                cout << r.top() << "\n";
                r.push(tmp);
            }
            else if(tmp < l.top()) {
                cout << l.top() << "\n";
                l.push(tmp);
                r.push(l.top());
                l.pop();
            }
            else {
                cout << tmp << "\n";
                r.push(tmp);
            }
        }
        else {
            if(tmp > r.top()) {
                cout << r.top() << "\n";
                l.push(r.top());
                r.pop();
                r.push(tmp);
            }
            else if(tmp < l.top()) {
                cout << l.top() << "\n";
                l.push(tmp);
            }
            else {
                cout << tmp << "\n";
                l.push(tmp);
            }
        }
    }

    

    return 0;
}