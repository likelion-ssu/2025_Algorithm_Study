#include <bits/stdc++.h>

#define USED -2
#define MAX 2000000000
using namespace std;


int arr[20][20]; // 꽃밭의 비용
int cost[20][20]; // 특정 위치를 사용했을 때에 대한 비용의 합
int n; // 꽃밭의 크기
int min_cost = MAX;

int get_best(int flower_amt, int sum_cost, unordered_set<int>& set) {
    if(flower_amt == 0) return sum_cost; // 값이 나옴
    if(sum_cost > min_cost) return MAX; // 백트래킹 탈출 조건
    int min = MAX;
    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < n - 1; j++) {
            // 이미 해당 꽃밭이 사용된 경우 건너뜀
            if(set.count(i * n + j) || set.count((i - 1) * n + j) || set.count((i + 1) * n + j)
            || set.count(i * n + (j - 1)) || set.count(i * n + (j + 1))) 
            continue;

            // 꽃밭 사용
            set.insert((i - 1) * n + j);
            set.insert((i + 1) * n + j);
            set.insert(i * n + (j - 1));
            set.insert(i * n + (j + 1));
            set.insert(i * n + j);
            
            int current_cost = get_best(flower_amt - 1, sum_cost + cost[i][j], set);
            min = min < current_cost ? min : current_cost;

            // 사용한 꽃밭 원위치
            set.erase((i - 1) * n + j);
            set.erase((i + 1) * n + j);
            set.erase(i * n + (j - 1));
            set.erase(i * n + (j + 1));
            set.erase(i * n + j);
        }
    }
    min_cost = min_cost < min ? min_cost : min;
    return min;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            cost[i][j] = 0; // 초기화
        }
    }

    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < n - 1; j++) {
            cost[i][j] += arr[i][j]; // 현위치
            cost[i][j] += arr[i - 1][j]; // 상
            cost[i][j] += arr[i + 1][j]; // 하
            cost[i][j] += arr[i][j - 1]; // 좌
            cost[i][j] += arr[i][j + 1]; // 우
        }
    }

    unordered_set <int> s;

    int res = get_best(3, 0, s);

    cout << res << "\n";

    return 0;
}