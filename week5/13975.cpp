#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
    int file_num;


    cin >> test_case;

    for(int i = 0; i < test_case; i++) {
        cin >> file_num;

        long long res = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;


        for(int i = 0; i < file_num; i++) {
            long long tmp;
            cin >> tmp;
            pq.push(tmp);
        }

        while(pq.size() > 1) {
            long long a, b;
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();

            res += a + b;
            pq.push(a + b);
        }

        cout << res << "\n";
    }

    return 0;
}
