// boj 16953: A -> B
# include <iostream>

using namespace std;

int main() {

    int A, B;
    int cnt = 1; // 횟수 카운트

    cin >> A >> B;

    while(B > A) {
        if (B % 2 == 0) { // 짝수이면
            B /= 2; // B 값 갱신 
        }
        else if (B % 10 == 1) { // 일의 자리가 1이면 
            B /= 10;
        }
        else {
            cout << -1 << "\n";
            return 0;
        }
        cnt++; // 카운트 추가 
    }

    if (A == B)
        cout << cnt << "\n";
    else 
        cout << -1 << "\n";

    return 0;
}

// 가능한 연산 두 가지
// 1. 2 곱하기
// 2. 1을 수의 가장 오른쪽에 추가하기 

// A를 B로 바꾸는데 필요한 연산의 최솟값 
// 탐욕법을 사용하며 가장 그 값에 가까운 결과가 나오는 것을 선택

// 거꾸로 접근?
// B의 값에서 끝 값이 1이면 1을 붙인 거로 하고, 짝수면 2로 나누기 