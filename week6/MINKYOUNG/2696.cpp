// BOJ 2696: 중앙값 구하기
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int M; 
        cin >> M;

        // 왼쪽: 최대 힙 / 오른쪽: 최소 힙
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;

        vector<int> medians;
        medians.reserve((M + 1) / 2);

        for (int i = 1; i <= M; ++i) {
            int x; 
            cin >> x;

            if (left.empty() || x <= left.top()) left.push(x);
            else right.push(x);

            // 왼쪽이 항상 오른쪽과 같거나 1 더 많게
            if (left.size() < right.size()) {
                left.push(right.top()); right.pop();
            } else if (left.size() > right.size() + 1) {
                right.push(left.top()); left.pop();
            }

            // i가 홀수일 때 중앙값 수집
            if (i & 1) medians.push_back(left.top());
        }

        // 출력
        cout << medians.size() << '\n';
        for (size_t i = 0; i < medians.size(); ++i) {
            if (i && i % 10 == 0) cout << '\n';
            if (i % 10) cout << ' ';
            cout << medians[i];
        }
        cout << '\n';
    }
    return 0;
}

// 수열의 홀수번째 수를 읽을 대마다, 지금까지 입력받은 값의 중앙값을 출력
// 어디까지 읽었는가에 대한 범위 판단이 필요함
// Priority queue에 넣어서 출력해야하는 번호를 계산하고 출력 
// -> 최대 힙과 최소 힙으로 나누어서 정렬함 

// 출력에서 10개씩 자름 