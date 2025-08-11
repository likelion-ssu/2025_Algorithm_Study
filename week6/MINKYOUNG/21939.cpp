// boj 21939: 문제 추천 시스템 Version 1
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P, L;
    cin >> N;

    // 문제 번호 -> 난이도
    map<int, int> p2l;
    // 난이도 -> 문제번호 집합(난이도 같으면 문제번호로 정렬)
    map<int, set<int>> lvl;

    for (int i=0; i<N; i++) { // N 라인 돌리기
        cin >> P >> L;
        p2l[P] = L;
        lvl[L].insert(P);
    }

    int M, x;
    cin >> M;
    string command;
    for (int j=0; j<M; j++) {
        cin >> command;

        // 명령어 1. recommend x
        if (command == "recommend") {
            cin >> x;
            if (x == 1) {
                // 가장 어려운 난이도(최대 L), 동률이면 문제번호 큰 것
                auto it = prev(lvl.end());        // max L
                int hardestL = it->first;
                int P_ans = *prev(it->second.end()); // set의 가장 큰 P
                cout << P_ans << '\n';
            } else { // x == -1
                // 가장 쉬운 난이도(최소 L), 동률이면 문제번호 작은 것
                auto it = lvl.begin();           // min L
                int easiestL = it->first;
                int P_ans = *it->second.begin(); // set의 가장 작은 P
                cout << P_ans << '\n';
            }
        }
        // 명령어 2. add P L
        else if (command == "add") {
            cin >> P >> L;
            // 기존에 있을 수도 있으니 정리
            auto it = p2l.find(P);
            if (it != p2l.end()) {
                int oldL = it->second;
                lvl[oldL].erase(P);
                if (lvl[oldL].empty()) lvl.erase(oldL);
            }
            p2l[P] = L;
            lvl[L].insert(P);
        }
        // 명령어 3. solved P
        else if (command == "solved") {
            cin >> P;
            int curL = p2l[P];
            p2l.erase(P);
            lvl[curL].erase(P);
            if (lvl[curL].empty()) lvl.erase(curL);
        }
    }

    return 0;
}

// 문제 번호 / 난이도로 정리
// 새로운 기능
// 1. recommend x
//    x = 1 가장 어려운 문제 / x = -1 가장 쉬운 문제
//    (겹친다면) 가장 어려운 문제 -> 문제 번호 큰 것 / 가장 쉬운 문제 -> 문제 번호 작은 것
// 2. add P L
//    난이도 L인 문제 번호 P 추가
// 3. solved P
//    문제 번호 P 제거

// recommend 명령어가 들어올 때 상황에 맞는 출력을 해야함
// -> map 사용 (문제 번호/난이도 각각 정렬을 위해 p2l, lvl 두 개 사용)
