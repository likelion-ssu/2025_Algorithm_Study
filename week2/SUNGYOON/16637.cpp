#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 괄호 추가하기 (DFS)

int n;              // 수식 길이
string s;           // 수식 문자열
int res = -2e9;     // 초기값 최소로 설정

// 계산 함수
int calc(int a, char op, int b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    return a * b;
}

// idx: 현재 위치, val: 지금까지 계산된 값
void dfs(int idx, int val) {
    if (idx >= n) {
        res = max(res, val); // 수식 탐색 완료 시, 현재 결과와 기존 최대값 비교 후 갱신
        return;
    }

    // 괄호 x
    char op = s[idx - 1];
    int num = s[idx] - '0'; // 정수변환
    dfs(idx + 2, calc(val, op, num));  //숫자 연산자 숫자 형식으므로 +2 진행

    // 괄호 o
    if (idx + 2 < n) {
        int a = s[idx] - '0';
        char op2 = s[idx + 1];
        int b = s[idx + 2] - '0';
        int tmp = calc(a, op2, b); // 괄호 안 계산 선행
        dfs(idx + 4, calc(val, op, tmp));
    }
}

int main() {
    cin >> n >> s;
    dfs(2, s[0] - '0');
    cout << res << '\n';
    return 0;
}
