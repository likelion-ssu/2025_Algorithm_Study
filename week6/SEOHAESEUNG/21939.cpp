#include <bits/stdc++.h>
using namespace std;


int n, m;
struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second != b.second) 
        return a.second < b.second;

        return a.first < b.first;
    }
};
multiset <pair <int, int>, cmp> problem_list;

int dp[100100];



void execution() {
    string cmd;
    cin >> cmd;

    if(cmd == "add") {
        pair <int, int> problem;
        cin >> problem.first >> problem.second;
        dp[problem.first] = problem.second;
        problem_list.insert(problem);    
    }

    else if(cmd == "recommend") {
        int x;
        cin >> x;
        pair <int, int> problem;
        if(x > 0) {
            problem = *problem_list.rbegin();
            cout << problem.first << "\n";
        }
        if(x < 0) {
            problem = *problem_list.begin();
            cout << problem.first << "\n";
        }
    }

    else if(cmd == "solved") {
        int p;
        cin >> p;
        int diff = dp[p];

        problem_list.erase({p, diff});  
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        pair <int, int> problem; // <번호, 난이도>
        cin >> problem.first >> problem.second;
        dp[problem.first] = problem.second;
        problem_list.insert(problem);
    }


    cin >> m;

    for(int i = 0; i < m; i++) {
        execution();
    }

    return 0;
}