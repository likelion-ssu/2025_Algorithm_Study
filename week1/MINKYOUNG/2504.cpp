// boj 2504: 괄호의 값
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

    stack<char> s; // 괄호를 담을 스택
    string str;
    int answer = 0, temp = 1; // temp는 중간값 계산

    cin >> str; // 전체를 받음
    for (int i=0; i<str.length(); i++) {

        if (str[i] == '(') {
            temp *= 2;
            s.push('(');
        }
        else if (str[i] == '[') {
            temp *= 3;
            s.push('[');
        }
        else if (str[i] == ')') {
            if (s.empty() || s.top() != '(') {
                answer = 0;
                break;
            }
            if (str[i-1] == '(') {
                answer += temp;
                temp /= 2;
                s.pop();
            }
            else {
                temp /= 2;
                s.pop();
            }
        }
        else if (str[i] == ']') {
            if (s.empty() || s.top() != '[') {
                answer = 0;
                break;
            }
            if (str[i-1] == '[') {
                answer += temp;
                temp /= 3;
                s.pop();
            }
            else {
                temp /= 3;
                s.pop();
            }
        }
    }

    // 잘못된 입력인 경우
    if (!s.empty())
        answer = 0;
    cout << answer << "\n";

    return 0;
}

// 입력을 받으면서 스택에 넣음 -> 짝이 들어오면 밑에 거랑 같이 pop -> 경우에 따라 그 값을 계산
// 값을 게산하는 것 또한 스택 이용 (스택 2개) -> ** 수정 