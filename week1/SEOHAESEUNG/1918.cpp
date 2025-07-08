#include <bits/stdc++.h>
using namespace std;

string permutation_1(deque<string> d);
deque<string> permutation_2(deque<string> d);
deque<string> permutation_3(deque<string> d);

string permutation_1(deque<string> d) {
    deque<string> tmp;
    while(d.size() > 0) {
        if(d.front() != "(" && d.front() != ")") {
            tmp.push_back(d.front());
            d.pop_front();
        }
        else if(d.front() == "(") {
            int additional_open_num = 1;
            d.pop_front();
            deque<string> inner_sentence;
            while(additional_open_num > 0) {
                if(d.front() == "(") {
                    additional_open_num++;
                }
                if(d.front() == ")") {
                    additional_open_num--;
                    if(additional_open_num == 0) {
                        d.pop_front();
                        break;
                    }
                }
                inner_sentence.push_back(d.front());
                d.pop_front();
            }
            tmp.push_back(permutation_1(inner_sentence));
        }
    }
    tmp = permutation_2(tmp);
    tmp = permutation_3(tmp);
    return tmp.front();
}

deque<string> permutation_2(deque<string> d) {
    deque<string> tmp;
        // 2. 곱셈, 나눗셈 처리
    while(d.size() > 0) {
        if(d.front() == "*" || d.front() == "/") {
            string s;

            // 연산 기호 분리
            string sign = d.front();
            d.pop_front();

            // 앞 문자 추가
            s += tmp.back();
            tmp.pop_back();

            // 뒷 문자 추가
            s += d.front();
            d.pop_front();
            
            // 연산 기호 추가
            s += sign;

            // 결과 추가
            tmp.push_back(s);
        }
        else {
            tmp.push_back(d.front());
            d.pop_front();
        }
    }
    return tmp;
}


deque<string> permutation_3(deque<string> d) {
    deque<string> tmp;
    // 3. 덧셈, 뺄셈 처리
    while(d.size() > 0) {
        if(d.front() == "+" || d.front() == "-") {
            string s;

            // 연산 기호 분리
            string sign = d.front();
            d.pop_front();

            // 앞 문자 추가
            s += tmp.back();
            tmp.pop_back();

            // 뒷 문자 추가
            s += d.front();
            d.pop_front();
            
            // 연산 기호 추가
            s += sign;

            // 결과 추가
            tmp.push_back(s);
        }
        else {
            tmp.push_back(d.front());
            d.pop_front();
        }
    }
    return tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    deque<string> start_d;
    deque<string> d;

    cin >> s;

    for(char c : s) {
        string tmp_string;
        tmp_string += c;
        start_d.push_back(tmp_string);
    }
    
    cout << permutation_1(start_d) << "\n";


    return 0;
}


//a + b + c * d
// a + b + cd*
// ab+ + cd*
// ab+cd*+

/*
1. stack에 하나하나 쌓는다
2. () 부터 처리해서 하나의 문자열로 합쳐버린다 -> 재귀적인 처리가 필요할듯?
3. * / 처리
4. + - 처리
*/