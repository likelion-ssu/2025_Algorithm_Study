#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   queue<int> q; // 큐 선언
   int N; 

   cin >> N;
   while (N--) {
    string str;
    cin >> str; // str에 다음 명령어 받기

    int c;
    if (!str.compare("push")){ // find 함수 대신 compare 사용
        cin >> c;
        q.push(c);
        continue; // push 일 때에만 출력값 없음
    } else if (!str.compare("pop")) {
        c= q.size()!=0 ? q.front() : -1; // 삼항 연산자 활용
        if (q.size()!=0) 
            q.pop();
    } 
    else if (!str.compare("size")) c= q.size();
    else if (!str.compare("empty")) c = q.empty() ? 1 : 0;
    else if (!str.compare("front")) c= q.size()!=0 ? q.front() : -1;
    else if (!str.compare("back")) c = q.size()!=0 ? q.back() : -1;

    cout << c << "\n"; // endl에서 \n으로 변경
   }


   return 0;
}