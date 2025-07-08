#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test_num;
    cin >> test_num;


    for(int i = 0; i < test_num; i++) {
        bool error = false;
        bool isReverse = false;
        string command;
        string arr;
        int n;
        deque <int> res;
        cin >> command;
        cin >> n;
        cin >> arr;
        
        arr = arr.substr(1, arr.length() - 2);

        stringstream sstream(arr);
        string each_integer;

        while(getline(sstream, each_integer, ',')) {
            //res_arr.push_back(stoi(each_integer));
            res.push_back(stoi(each_integer));
        }

        for(int j = 0; j < command.length(); j++) {
            if(command[j] == 'R') {
                isReverse = !isReverse;
            }
            else if(command[j] == 'D') {
                if(res.size() < 1) {
                    error = true;
                    break;
                }
                if(isReverse) {
                    res.pop_back();
                }
                else {
                    res.pop_front();
                }
            }
        }
        if(error) cout << "error\n";
        else {
            cout << "[";
            int size = res.size();
            for(int j = 0; j < size; j++) {
                if(!isReverse) {
                    cout << res.front();
                    res.pop_front();
                }
                else {
                    cout << res.back();
                    res.pop_back();
                }
                if(j != size - 1) cout << ",";
            }
            cout << "]\n";
        }
    }

    return 0;
}