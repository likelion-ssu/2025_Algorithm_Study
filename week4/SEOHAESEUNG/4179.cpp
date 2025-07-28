#include <bits/stdc++.h>
using namespace std;

int r, c;
char maze[1010][1010];
int jihoon_speed[1010][1010];
int fire_speed[1010][1010];
bool impossible = false;
queue <pair <int, int>> fire; // <row, column, special_index>
queue <pair <int, int>> jihoon; // <row, column, time>


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;
    
    for(int i = 0; i < 1010; i++) {
        for(int j = 0; j < 1010; j++) {
            fire_speed[i][j] = INT_MAX;
        }
    }


    for(int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < c; j++) {
            maze[i][j] = s[j];
            if(maze[i][j] == 'J') {
                if(i == 0 || i == r - 1 || j == 0 || j == c - 1) {
                    cout << "1\n";
                    return 0;
                }
                jihoon.push({i, j});
            }
            if(maze[i][j] == 'F') {
                fire.push({i, j});
                fire_speed[i][j] = 0;
            }
        }
    }

    while(!fire.empty()) {
        int row = fire.front().first;
        int column = fire.front().second;
        int tmp_speed = fire_speed[row][column];
        
        if(row > 0) {
            if(fire_speed[row - 1][column] != INT_MAX || maze[row - 1][column] == '#') {
            }
            else if(maze[row - 1][column] == '#') {
                fire_speed[row - 1][column] = -1;
            }
            else {
                fire_speed[row - 1][column] = tmp_speed + 1;
                fire.push({row - 1, column});
            }
        }
        if(row < r - 1) {
            if(fire_speed[row + 1][column] != INT_MAX || maze[row + 1][column] == '#') {
            }
            else if(maze[row + 1][column] == '#') {
                fire_speed[row + 1][column] = -1;
            }
            else {
                fire_speed[row + 1][column] = tmp_speed + 1;
                fire.push({row + 1, column});
            }
        }
        if(column > 0) {
            if(fire_speed[row][column - 1] != INT_MAX || maze[row][column - 1] == '#') {
            }
            else if(maze[row][column - 1] == '#') {
                fire_speed[row][column - 1] = -1;
            }
            else {
                fire_speed[row][column - 1] = tmp_speed + 1;
                fire.push({row, column - 1});
            }
        }
        if(column < c - 1) {
            if(fire_speed[row][column + 1] != INT_MAX || maze[row][column + 1] == '#') {
            }
            else if(maze[row][column + 1] == '#') {
                fire_speed[row][column + 1] = -1;
            }
            else {
                fire_speed[row][column + 1] = tmp_speed + 1;
                fire.push({row, column + 1});
            }
        }
        fire.pop(); 
    }

    while(!jihoon.empty()) {
        int row = jihoon.front().first;
        int column = jihoon.front().second;
        int tmp_speed = jihoon_speed[row][column];
        
        if(row > 0) {
            if(jihoon_speed[row - 1][column] != 0) {
            }
            else if(maze[row - 1][column] == '#') {
                jihoon_speed[row - 1][column] = -1;
            }
            else {
                jihoon_speed[row - 1][column] = tmp_speed + 1;
                jihoon.push({row - 1, column});
            }
        }
        if(row < r - 1) {
            if(jihoon_speed[row + 1][column] != 0) {
            }
            else if(maze[row + 1][column] == '#') {
                jihoon_speed[row + 1][column] = -1;
            }
            else {
                jihoon_speed[row + 1][column] = tmp_speed + 1;
                jihoon.push({row + 1, column});
            }
        }
        if(column > 0) {
            if(jihoon_speed[row][column - 1] != 0) {
            }
            else if(maze[row][column - 1] == '#') {
                jihoon_speed[row][column - 1] = -1;
            }
            else {
                jihoon_speed[row][column - 1] = tmp_speed + 1;
                jihoon.push({row, column - 1});
            }
        }
        if(column < c - 1) {
            if(jihoon_speed[row][column + 1] != 0) {
            }
            else if(maze[row][column + 1] == '#') {
                jihoon_speed[row][column + 1] = -1;
            }
            else {
                jihoon_speed[row][column + 1] = tmp_speed + 1;
                jihoon.push({row, column + 1});
            }
        }
        jihoon.pop(); 
    }

    int res = INT_MAX;

    for(int i = 0; i < r; i++) {
        if(jihoon_speed[i][0] > 0 && jihoon_speed[i][0] < fire_speed[i][0])
        res = min(res, jihoon_speed[i][0]);

        if(jihoon_speed[i][c - 1] > 0 && jihoon_speed[i][c - 1] < fire_speed[i][c - 1])
        res = min(res, jihoon_speed[i][c - 1]);
    }

    for(int i = 0; i < c; i++) {
        if(jihoon_speed[0][i] > 0 && jihoon_speed[0][i] < fire_speed[0][i])
        res = min(res, jihoon_speed[0][i]);

        if(jihoon_speed[r - 1][i] > 0 && jihoon_speed[r - 1][i] < fire_speed[r - 1][i])
        res = min(res, jihoon_speed[r - 1][i]);
    }

    if(res == INT_MAX) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << res + 1 << "\n";

    return 0;
}