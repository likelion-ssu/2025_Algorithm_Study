#include <bits/stdc++.h>
using namespace std;


int t, k;

void f() {
    cin >> k;
    string cmd;
    unordered_set <int> s;
    int id = 0;

    priority_queue <pair <int, int>> max_queue;
    priority_queue <pair <int, int>, vector<pair <int, int>>, greater <pair <int, int>>> min_queue;

    for(int i = 0; i < k; i++) {
        cin >> cmd;

        if(cmd == "I") {
            int num;
            cin >> num;

            max_queue.push({num, id});
            min_queue.push({num, id});
            s.insert(id);
            id++;
        }
        else if(cmd == "D") {
            int num;
            cin >> num;

            //if(max_queue.empty() || min_queue.empty()) continue;

            if(num == 1) {
                pair <int, int> tmp;
                

                while(max_queue.size() > 0 && !s.count(max_queue.top().second)) {
                    max_queue.pop();
                }

                if(max_queue.empty() || min_queue.empty()) continue;

                tmp = max_queue.top();
                max_queue.pop();

                s.erase(tmp.second);
            }
            else if(num == -1) {
                pair <int, int> tmp;

                while(min_queue.size() > 0 && !s.count(min_queue.top().second)) {
                    min_queue.pop();
                }

                if(max_queue.empty() || min_queue.empty()) continue;

                tmp = min_queue.top();
                min_queue.pop();

                s.erase(tmp.second);
            }
        }
    }

    while(!max_queue.empty() && !s.count(max_queue.top().second)) max_queue.pop();
    while(!min_queue.empty() && !s.count(min_queue.top().second)) min_queue.pop();


    if(max_queue.empty()) {
        cout << "EMPTY\n";
    }
    else {
        cout << max_queue.top().first << " " << min_queue.top().first << "\n";
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    
    for(int i = 0; i < t; i++) {
        f();
    }

    return 0;
}