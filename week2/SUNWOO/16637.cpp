#include <bits/stdc++.h>
using namespace std;

int n, answer = -1e9;
string expr;

int calc(int a, int b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else return a * b;
}

void dfs(int idx, int total) {
    if (idx >= n) {
        answer = max(answer, total);
        return;
    }

    char op = (idx == 0) ? '+' : expr[idx - 1];
    int cur = expr[idx] - '0';

    // 괄호 없이 계산
    dfs(idx + 2, calc(total, cur, op));

    // 괄호를 쳐서 계산
    if (idx + 2 < n) {
        int next = expr[idx + 2] - '0';
        char nextOp = expr[idx + 1];
        int bracket = calc(cur, next, nextOp);
        dfs(idx + 4, calc(total, bracket, op));
    }
}

int main() {
    cin >> n >> expr;
    dfs(0, 0);
    cout << answer;
    return 0;
}