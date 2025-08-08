#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int N, P, L, M;
string str;

struct Problem {
   int diff; // 난이도
   int id; // 문제 번호
};

// 직접 정의한 비교 함수
// 함수 호출 연산자 오버로딩
struct Cmp {
   bool operator()(const Problem& a, const Problem& b) const {
      if (a.diff!= b.diff) return a.diff < b.diff; // 난이도가 낮으면 더 작다 (앞에)
      else return a.id < b.id; // 문제 번호가 작으면 더 작다(앞에)
   }
};

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   set<Problem, Cmp> problems; 
   // 문제를 저장하는 자료구조 선언
   unordered_map<int, int> pos; 
   // 문제 번호에 대한 난이도를 저장

   cin >> N; // 문제 개수

   for (int i=0; i<N; i++){
      // 문제를 넣고
      cin >> P >> L;
      problems.insert({L,P});
      pos[P]= L;
   }
   
   cin >> M;

   for (int i=0; i<M; i++){
      // 명령문 실행
      cin >> str;
      if (str=="add"){
         cin >> P >> L;
         problems.insert({L,P});
         pos[P]= L;
      } else if (str=="solved"){
         cin >> P;
         // 받은 문제 번호를 가지고 set에서 삭제
         problems.erase({pos[P],P});
      } else if (str=="recommend") {
         cin >> L;
         if (L==1) {
            // 가장 어려운
            cout << problems.rbegin()->id << "\n";
         } else {
            // 가장 쉬운
            cout << problems.begin()->id << "\n";
         }
      }
   }

   return 0;
}