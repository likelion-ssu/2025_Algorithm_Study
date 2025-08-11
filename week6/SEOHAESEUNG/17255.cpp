#include <bits/stdc++.h>
using namespace std;

set <string> s;
queue <tuple <int, int, string>> q; // start, end, process


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int len = str.length();

    for(int i = 0; i < len; i++) {
        string x = "";
        q.push({i, i, str[i] + x});
    }

    while(!q.empty()) {
        tuple <int, int, string> tmp;
        tmp = q.front();

        int start = get<0>(tmp);
        int end = get<1>(tmp);
        string process = get<2>(tmp);

        if(start == 0 && end == len - 1) {
            s.insert(process);
        }
        
        if(start > 0) {
            q.push(make_tuple(start - 1, end, process + " " + str.substr(start - 1, end - (start - 1) + 1)));
        }
        if(end < len - 1) {
            q.push(make_tuple(start, end + 1, process + " " + str.substr(start, end + 1 - start + 1)));
        }

        q.pop();
    }
    
    /*
    for(string tmp : s) {
        cout << "* " << tmp << "\n";
    }
    */

    cout << s.size() << "\n";
    
}