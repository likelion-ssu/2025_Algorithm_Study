#include <bits/stdc++.h>
#define OPERAMT n / 2
#define NUMAMT n / 2 + 1

using namespace std;

vector <int> numeric;
vector <char> oper;
bool if_paren[40];
int n;

int make_res(vector <int>numCopy, vector <char>operCopy);
int make_condition(bool isParen, int index);
int operation(int a, int b, char sign);


int make_res(vector <int>numCopy, vector <char>operCopy) {
    bool check_num[40] = {false, };
    bool check_oper[40] = {false, };
    // 괄호식 먼저 계산
    for(int i = 0; i < OPERAMT; i++) {
        if(if_paren[i]) {
            numCopy[i] = operation(numCopy[i], numCopy[i + 1], operCopy[i]);
            // 끝나고 지워야함!
            check_num[i + 1] = true;
            check_oper[i] = true;

            // numCopy.erase(numCopy.begin() + i + 1);
            // operCopy.erase(operCopy.begin() + i);
        }
    }
    
    int res = numCopy[0];

    // 계산 완료된 식 정리
    for(int i = 0; i < OPERAMT; i++) {
        if(if_paren[i]) continue;
        res = operation(res, numCopy[i + 1], operCopy[i]);
    }

    return res;
}

int make_condition(bool isParen, int index) {
    if(index >= OPERAMT) {
        // 괄호 선택 완료, 계산식 진행
        return make_res(numeric, oper);
    } 
    if(isParen) {
        // 이전 부분식에서 이미 괄호 만들었음
        if_paren[index] = false;
        return make_condition(false, index + 1);
    }
    else {
        // 괄호를 넣지 않음
        if_paren[index] = false;
        int case1 = make_condition(false, index + 1);
        // 괄호를 넣음
        if_paren[index] = true;
        int case2 = make_condition(true, index + 1);
        return case1 > case2 ? case1 : case2;
    }
}


int operation(int a, int b, char sign) {
    if(sign == '+') return a + b;
    else if(sign == '-') return a - b;
    else return a * b;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> n;
    cin >> s;

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0)
        numeric.push_back(s[i] - '0');
        else
        oper.push_back(s[i]);
    }

    cout << make_condition(false, 0) << "\n";

    return 0;
}