// boj 2493: 탑
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> heights(N + 1); // 탑의 높이 (1-based index)
    for (int i = 1; i <= N; ++i) {
        cin >> heights[i];
    }

    stack<pair<int, int>> s; // {index, height}
    vector<int> answer(N + 1);

    for (int i = 1; i <= N; ++i) {
        while (!s.empty() && s.top().second < heights[i]) {
            s.pop();
        }

        if (!s.empty()) {
            answer[i] = s.top().first; // 수신한 탑의 번호
        } else {
            answer[i] = 0; // 수신한 탑 없음
        }

        s.push({i, heights[i]});
    }

    for (int i = 1; i <= N; ++i) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}

// 앞에 들어간 것중에 높이가 큰 곳에 수신을 보내게 됨
// 출력은 1부터 셌을 때의 번호를 출력