#include <bits/stdc++.h>
using namespace std;

int n;
int target;
bool broken[10];

int ab(int a) {
    return a > 0 ? a : -a;
}


int f(int x) {
    int min = ab(x - 100);
    for(int i = 0; i <= 1000000; i++) {
        bool is_broken = false;
        string s = to_string(i);
        for(int j = 0; j < s.length(); j++) {
            if(broken[s[j] - '0']) {
                is_broken = true;
                break;
            }
        }
        if(!is_broken) {
            int tmp = ab(x - i) + s.length();
            min = min < tmp ? min : tmp;
        }
    }
    return min;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> target;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        broken[tmp] = true;
    }

    cout << f(target) << "\n";

    return 0;
}