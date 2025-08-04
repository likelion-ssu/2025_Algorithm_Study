#include <bits/stdc++.h>
using namespace std;

int n, k;
int sensor[10100];
int dis_sensor[10100];

bool compare(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> sensor[i];
    }

    sort(sensor, sensor + n);

    for(int i = 0; i < n - 1; i++) {
        dis_sensor[i] = sensor[i + 1] - sensor[i];
    }

    sort(dis_sensor, dis_sensor + n - 1, compare);

    for(int i = 0; i < k - 1; i++) {
        dis_sensor[i] = 0;
    }

    int res = 0;

    for(int i = 0; i < n - 1; i++) {
        res += dis_sensor[i];
    }

    cout << res << "\n";


    return 0;
}