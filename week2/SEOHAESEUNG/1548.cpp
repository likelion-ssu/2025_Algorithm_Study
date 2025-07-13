#include <bits/stdc++.h>
using namespace std;

int max_size = 0;

int return_big(int a, int b) {
    return a > b ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;


    vector <int> arr;
    int tmp;

    for(int i = 0; i < n; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }

    if(n < 3) {
        cout << n << "\n";
        return 0;
    }


    sort(arr.begin(), arr.end());

    int max_len = 2;

    for(int i = 0; i < n - 3; i++) {
        for(int j = i + 2; j < n; j++) {
            if(arr[i] + arr[i + 1] <= arr[j]) break;
            max_len = return_big(max_len, j - i + 1);
        }
    }

    cout << max_len << "\n";

    return 0;
}
