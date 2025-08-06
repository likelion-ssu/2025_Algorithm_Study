#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int N,M, ans=0;
set<string> st;
string str;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> N >> M;

   for (int i=0; i<N; i++){
        cin >> str;
        st.insert(str);
   }

   for (int i=0; i<M; i++){
    cin >> str;
    if (st.find(str)!=st.end()) ans++;
   }

   cout << ans;
   return 0;
}