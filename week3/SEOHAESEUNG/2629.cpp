#include <bits/stdc++.h>
using namespace std;

int block_num;
int bead_num;

int block_weight[33]; // 추의 무게
int bead_weight[10]; // 구슬의 무게

int dp[80900]; // 0~39999 => (-40000 ~ -1) , 40000 ~ => 0 ~


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> block_num;
    for(int i = 0; i < block_num; i++) {
        cin >> block_weight[i];
    }

    cin >> bead_num;
    for(int i = 0; i < bead_num; i++) {
        cin >> bead_weight[i];
    }

    // 기본적으로 평형 상태가 가능하기 때문에 초기화
    dp[40000] = 50000;

    for(int i = 0; i < block_num; i++) {
        for(int j = 0; j < 80900; j++) {
            // 하나의 추가 여러번 더해지는 상황을 방지하기 위해 dp[j]가 i + 1번째 추를 더해서 만들어진건지 확인
            if(dp[j] > 0 && dp[j] != i + 1) {
                // 이미 만들 수 있는 무게가 현재 추를 더하거나 빼서 만들어지는 경우를 대비한 조건문
                if(dp[j + block_weight[i]] == 0) dp[j + block_weight[i]] = i + 1;
                if(dp[j - block_weight[i]] == 0) dp[j - block_weight[i]] = i + 1;
            }
        }
    }

    for(int i = 0; i < bead_num; i++) {
        if(dp[bead_weight[i] + 40000] > 0) {
            cout << "Y "; 
        }
        else {
            cout << "N ";
        }
    }
    cout << "\n";


    return 0;
}