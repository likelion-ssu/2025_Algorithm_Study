#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> combination_vector;

void combination(int index, int combination_size, int data_amt, vector<pair<int, int>> origin, vector<int> res) {
    // 완성된 조합 추가
    if(res.size() == combination_size * 2) {
        combination_vector.push_back(res);
        return;
    }
    // 미완성된 조합에 새로운 괄호쌍 추가
    for(int i = index + 1; i < data_amt; i++) {
        res.push_back(origin[i].first);
        res.push_back(origin[i].second);
        combination(i, combination_size, data_amt, origin, res);
        res.pop_back();
        res.pop_back();
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string origin;
    cin >> origin;

    int paren_num = 0; // 괄호 수
    vector<pair<int, int>> v;; // 괄호쌍을 저장할 배열
    stack<int> s; // 괄호 처리를 위한 스택

    // 괄호 위치 처리
    for(int i = 0; i < origin.length(); i++) {
        if(origin[i] != '(' && origin[i] != ')') continue;
        if(origin[i] == '(') {
            s.push(i);
            continue;
        }
        if(origin[i] == ')') {
            pair<int, int> tmp;
            tmp.first = s.top();
            tmp.second = i;
            s.pop();
            v.push_back(tmp);
            paren_num++;
        }
    }

    // 괄호쌍 조합 생성
    for(int i = 1; i <= paren_num; i++) {
        vector<int> tmp;
        combination(-1, i, paren_num, v, tmp);
    }

    /*
    // Test
    for(int i = 0; i < combination_vector.size(); i++) {
        for(int j = 0; j < combination_vector[i].size(); j++) {
            cout << combination_vector[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    */

    set<string> total_res;
    for(int i = 0; i < combination_vector.size(); i++) {
        vector<int> exception = combination_vector[i];
        string tmp_string = origin;
        string res_string;
        int len_res_string = 0;

        // 제외 문자 처리
        for(int j = 0; j < exception.size(); j++) {
            tmp_string[exception[j]] = '!';
        }

        for(int j = 0; j < tmp_string.length(); j++) {
            if(tmp_string[j] == '!') continue;
            res_string += tmp_string[j]; 
        }

        total_res.insert(res_string);
    } 

    //sort(total_res.begin(), total_res.end());
    
    for(const string& res : total_res) {
        cout << res << "\n";
    }

    return 0;
}