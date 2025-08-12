#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string expression;
int N, resMax = -2147483648;

// 두 정수와 연산자를 받아 계산 결과 반환
int calculator(int operand1, int operand2, char optr) {
    switch (optr) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
    }
    return 0;
}

// idx: 현재 연산자 위치 (expression에서)
// sum: 지금까지 계산된 누적 결과
void dfs(int idx, int sum) {
    if (idx >= N) { // 수식 끝까지 도달
        resMax = max(resMax, sum);
        return;
    }
    // 1. 괄호 없이 계산: 단순 계산하고 뒤로 넘김
    if (idx + 1 < N) {
        int val = calculator(sum, expression[idx + 1] - '0', expression[idx]);
        dfs(idx + 2, val); // 다음 연산자로 넘어감
    }
    // 2. 괄호를 쳐서 다음 연산을 먼저 계산 
    // 여기서 중요한 건 현재 연산자 위치의 앞뒤로 괄호를 묶는 게 아니고 현재 연산자의 다음 연산자 앞뒤로 괄호로 묶음.
    // 현재 연산자 위치에 괄호를 묶는 건 1번(괄호 없이 계산)에서 처리되고 있기 때문
    if (idx + 2 < N) {
        int bracket = calculator(expression[idx + 1] - '0', expression[idx + 3] - '0', expression[idx + 2]);
        int val = calculator(sum, bracket, expression[idx]);
        dfs(idx + 4, val);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> expression;

    // 수식의 길이가 1일 때
    if (N == 1) {
        cout << (expression[0] - '0') << '\n';
        return 0;
    }
    dfs(1, expression[0] - '0'); // 첫 번째 숫자에서 시작
    cout << resMax << '\n';
    return 0;
}
