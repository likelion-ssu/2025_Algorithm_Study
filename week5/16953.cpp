#include <bits/stdc++.h>
using namespace std;

int a, b;

// 현재수, 연산 횟수
int f(int x, int operation) {
    if(x == a) return operation;
    int res = INT_MAX;  // 연산이 가능한지 저장할 변수

    if(x < a) return -1; // 연산 불가능(기존 수보다 작아짐)

    if(x % 2 == 0) res = f(x / 2, operation + 1); // 2로 나눈 경우
    if(x > 10 && x % 10 == 1) res = min(res, f(x / 10, operation + 1)); // 일의 자리가 1인 경우 제거

    if(res == INT_MAX) return -1; // 연산 불가능

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;

    cout << f(b, 1) << "\n";

    return 0;
}
