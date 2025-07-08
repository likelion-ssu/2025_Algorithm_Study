#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   deque<int> deq; // 덱 선언
   int N; 

   cin >> N;
   while (N--) {
    string str;
    cin >> str; // str에 다음 명령어 받기

    int c;
    if (!str.compare("push_front")){
        cin >> c;
        deq.push_front(c);
        continue; // push 일 때에만 출력값 없음
    } 
    else if (!str.compare("push_back")){
        cin >> c;
        deq.push_back(c);
        continue; // push 일 때에만 출력값 없음
    }else if (!str.compare("pop_front")) {
        c= deq.size()!=0 ? deq.front() : -1; // 삼항 연산자 활용
        if (deq.size()!=0) 
            deq.pop_front();
    } else if (!str.compare("pop_back")) {
        c= deq.size()!=0 ? deq.back() : -1; // 삼항 연산자 활용
        if (deq.size()!=0) 
            deq.pop_back();
    } 
    else if (!str.compare("size")) c= deq.size();
    else if (!str.compare("empty")) c = deq.empty() ? 1 : 0;
    else if (!str.compare("front")) c = deq.size()!=0 ? deq.front() : -1;
     else if (!str.compare("back")) c = deq.size()!=0 ? deq.back() : -1;

    cout << c << "\n";
   }


   return 0;
}