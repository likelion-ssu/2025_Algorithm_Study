#include <bits/stdc++.h>
using namespace std;

int return_small(int a, int b);
int balance(int index);
int sum_abil();

int arr[30][30];
int seperate[30];
int n;

// 절댓값 리턴 함수
int ab_value(int a) {
    return a >= 0 ? a : -a;
}

// 작은값 리턴 함수
int return_small(int a, int b) {
    return a < b ? a : b;
}

// 최소 밸런스 차이를 찾는 함수
int balance(int index) {
    int team_1;
    int team_2;
    if(index >= n - 1) {
        return sum_abil();
    }
    else {
        // index 번째 선수가 false 팀에 들어간 경우
        team_1 = balance(index + 1);
        seperate[index] = 1;
        // index 번째 선수가 true 팀에 들어간 경우
        team_2 = balance(index + 1);
        // 원상태 복귀
        seperate[index] = 0;

        return return_small(team_1, team_2);
    }
}

// 각 팀의 능력치 합을 구해 차를 구하는 함수
int sum_abil() {
    int team_1 = 0;
    int team_2 = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // 팀이 일치할때
            if(seperate[i] == seperate[j]) {
                // true 팀일때
                if(seperate[i]) {
                    team_1 += arr[i][j];
                }
                // false 팀일때
                else {
                    team_2 += arr[i][j];
                }
            }
        }
    }
    return ab_value(team_1 - team_2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
        cin >> arr[i][j];
    }

    cout << balance(0) << "\n";

}