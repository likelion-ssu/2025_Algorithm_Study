// boj: 16637: 괄호 추가하기
#include <iostream>
#include <stack>

using namespace std;

int N;
string expr;
int answer = -1111111111;

// 연산 함수 분리
int calculate(int a, int b, char op) {
    // 조건 분기
    if (op == '+') 
        return a + b;
    else if (op == '-') 
        return a - b;
    else 
        return a * b;
}

// 가능한 모든 조합 탐색 by DFS
void dfs(int index, int result) { 
    if (index >= N) { // 끝까지 탐색한 경우 
        answer = max(answer, result); // 현재 결과와 최댓값과 비교하여 갱신
        return;
    }

    // 상황1. 괄호 x
    char op = (index == 0) ? '+' : expr[index - 1]; // 첫 수는 연산자가 없으므로 '+'를 가정
    int num = expr[index] - '0'; // 문자형 숫자를 정수형으로 변환

    // 다음 숫자로 점프
    dfs(index + 2, calculate(result, num, op));

    // 상황2. 괄호 o
    if (index + 2 < N) {
        int a = expr[index] - '0';     // 괄호 내 첫 숫자
        char op2 = expr[index + 1];  // 괄호 내 연산자
        int b = expr[index + 2] - '0'; // 괄호 내 두 번째 숫자

        // 괄호 안 계산
        int result2 = calculate(a, b, op2); 
        // 괄호 안 계산 전체 계산에 포함
        dfs(index + 4, calculate(result, result2, op)); 
    }
}

int main() {
    cin >> N >> expr; // expr로 수식 전체 받음

    dfs(0, 0); // index = 0, 누적합 = 0
    cout << answer << '\n';

    return 0;
}

// 괄호 안에는 연산자가 하나만 들어 있어야 한다
// 중첩된 괄호 사용 불가 
// 괄호를 추가해 얻을 수 있는 최대값 -> "완전 탐색" 재귀 / DFS 

// 연산자는 + / - / * 셋 중 하나이기에 조건문 분기 
// 결과를 누적으로 쌓아가며 가장 큰 값을 계산헤야함 (큰 값이 나오면 갱신) by DFS