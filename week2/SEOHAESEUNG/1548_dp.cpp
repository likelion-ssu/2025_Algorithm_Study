#include <bits/stdc++.h>
using namespace std;

int max_size = 0;

int dp[100][100];

int return_big(int a, int b) {
    return a > b ? a : b;
}

int max_num(vector <int> &arr, int start, int end, int size) {
    if(dp[start][end] > 0) return dp[start][end];
    if(size < 3) {
        dp[start][end] = 2;
        return dp[start][end];
    }
    if(arr[start] + arr[start + 1] > arr[end]) {
        dp[start][end] = size;
        return size;
    }
    dp[start][end] = return_big(max_num(arr, start + 1, end, size - 1), max_num(arr, start, end - 1, size - 1));
    return dp[start][end];
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

    cout << max_num(arr, 0, arr.size() - 1, arr.size()) << "\n";

    return 0;
}