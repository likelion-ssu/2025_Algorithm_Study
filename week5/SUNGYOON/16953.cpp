#include <iostream>
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    int operations = 1; // 연산 횟수 최소 1 

    while (B > A) {
        // B가 짝수면 2로 나눌 수 있음
        if (B % 2 == 0) {
            B /= 2;
        }
        // B가 1로 끝나면, 맨 뒤의 1 제거
        else if (B % 10 == 1) {
            B /= 10;
        }
        // 위 두 가지 연산이 불가능하면 A로 만들 수 없음
        else {
            cout << -1 << endl;
            return 0;
        }
        operations++; 
    }

    // A와 같아졌으면 정답, 아니면 만들 수 없음
    if (B == A) {
        cout << operations << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
