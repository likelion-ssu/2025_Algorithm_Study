#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first - a.second < b.first - b.second;
}

int left(pair<int, int> a) {
    return a.first - a.second;
}

int right(pair<int, int> a) {
    return a.first + a.second;
}

pair<int, int> arr[200200];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    bool res = true;

    int n;
    stack <pair<int, int>> s;


    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr + n, compare);

    /*
    cout << "------\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i].first << " " << arr[i].second << " ";
    }
    cout << "\n----\n";
    */
    

    for(int i = 0; i < n; i++) {
        if(s.size() != 0) {
            if(right(s.top()) == left(arr[i]) || left(s.top()) == left(arr[i])) {
                //cout << "Reason1\n";
                res = false;
                break;
            }
        }
        while(s.size() > 0 && right(s.top()) < left(arr[i])) {
            s.pop();
        }
        if(s.size() == 0) {
            s.push(arr[i]);
            continue;
        }
        
        /*
        if(right(s.top()) == left(arr[i])) {
            //cout << "Reason1\n";
            res = false;
            break;
        }
        */
            
        if(right(s.top()) <= right(arr[i])) {
            //cout << "Reason2\n";
            res = false;
            break;
        }
        else {
            s.push(arr[i]);
        }
    }
    if(res) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}