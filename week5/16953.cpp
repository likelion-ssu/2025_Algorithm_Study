#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    int cnt = 1; // 시작 포함해서 연산 횟수 1부터 시작
    while (B > A) {
        if (B % 2 == 0) B /= 2;         // 2로 나눠짐 → 이전 단계로 되돌리기
        else if (B % 10 == 1) B /= 10;  // 끝자리가 1이면 → 1 제거
        else break;                     // 둘 다 안 되면 불가능
        cnt++;
    }

    if (B == A) cout << cnt << "\n";   // A로 도달했으면 출력
    else cout << -1 << "\n";           // 불가능
    return 0;
}
