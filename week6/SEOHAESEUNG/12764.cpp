// 12764.cpp
#include <bits/stdc++.h>
using namespace std;

int n;

// 우선순위 큐(q)에서 끝나는 시간이 빠른 순서대로 정렬하기 위한 함수 (sort와 반대!)
struct compare {
    bool operator() (pair <int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};

// 시작 시간 오름차순으로 저장하기 위한 함수
bool Compare(pair <int, int> a, pair <int, int> b) {
    return a.first < b.first;
}

priority_queue <pair <int, int>, vector<pair<int, int>>, compare> using_computer; // {끝나는 시간, 이용중인 컴퓨터 번호}를 저장하는 우선순위 큐
priority_queue <int, vector<int>, greater<int>> available_computer; // 현재 이용가능한 컴퓨터를 위한 우선순위 큐

vector <pair <int, int>> arr;  // {시작 시간, 종료 시간}으로 input data 저장하는 배열
int res[100100]; // 컴퓨터별 사용자 수를 저장하는 배열

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int start, end;
    int max_computer = 0; // 현재 필요한 최대 컴퓨터 수
    int next_computer = -1; // 현재 사용자가 이용해야 할 컴퓨터 번호

    // 시작시간 오름차순 정렬
    for(int i = 0; i < n; i++) {
        cin >> start >> end;
        arr.push_back({start, end});
    }
    sort(arr.begin(), arr.end(), Compare);

    // q 가 가지는 정보 -> {끝나는 시간, 사용중인 컴퓨터 정보}
    for(int i = 0; i < n; i++) {
        // 현재 사용 가능한 컴퓨터 추가 (현재 사용자 시작하는 시간을 통해 이미 사용이 끝난 컴퓨터 q -> available_computer)
        while(using_computer.size() > 0 && arr[i].first > using_computer.top().first) {
            available_computer.push(using_computer.top().second);    
            using_computer.pop();
        }

        // 사용 가능 컴퓨터가 없는 경우
        if(available_computer.size() == 0) {
            next_computer = ++max_computer;
        }
        // 사용 가능 컴퓨터가 있는 경우
        else {
            next_computer = available_computer.top();
            available_computer.pop();
        }

        // 사용 중인 컴퓨터 추가
        using_computer.push({arr[i].second, next_computer});
        // 사용 중인 컴퓨터 번호에 컴퓨터 수 증가
        res[next_computer]++;
    }

    cout << max_computer << "\n";
    for(int i = 1; i <= max_computer; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}