#include <bits/stdc++.h>
using namespace std;

int arr[40][40];
int sati_max[40];

int n, m;

void get_max(int m) {
    for(int i = 0; i < n; i++) {
        sati_max[i] = arr[i][m] > sati_max[i] ? arr[i][m] : sati_max[i];
    }
}

int return_sati() {
    int val = 0;
    for(int i = 0; i < n; i++)
    val += sati_max[i];

    return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
        cin >> arr[i][j];
    }

    int res = 0; 

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < m; k++) {
                get_max(i);
                get_max(j);
                get_max(k);

                res = res > return_sati() ? res : return_sati();

                memset(sati_max, 0, sizeof(sati_max));
            }
        }

    }


    cout << res << "\n";

    return 0;
}