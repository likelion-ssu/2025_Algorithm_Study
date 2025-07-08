#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   stack<int> stck; // 스택 선언
   int N; 

   cin >> N;
   while (N--) {
    string str;
    cin >> str; // str에 다음 명령어 받기

    int c;
    if (!str.compare("push")){
        cin >> c;
        stck.push(c);
        continue; // push 일 때에만 출력값 없음
    } else if (!str.compare("pop")) {
        c= stck.size()!=0 ? stck.top() : -1; // 삼항 연산자 활용
        if (stck.size()!=0) 
            stck.pop();
    } 
    else if (!str.compare("size")) c= stck.size();
    else if (!str.compare("empty")) c = stck.empty() ? 1 : 0;
    else if (!str.compare("top")) c = stck.size()!=0 ? stck.top() : -1;

    cout << c << "\n";
   }


   return 0;
}