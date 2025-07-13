#include <bits/stdc++.h>
#define DIR 8
using namespace std;

int arr[20][20];
int max_square = -1;
int n, m;

int check_square(int n);
int return_big(int a, int b);
int get_max(int y, int x);
int get_num(int row, int column, int row_sub, int column_sub);


// 제곱수인지 확인
int check_square(int n) {
    if(n == 0) return 0;
    int root = (int)(sqrt(n));
    if(root * root == n) return n;
    else return -1;
}

// 큰 값 리턴
int return_big(int a, int b) {
    return a > b ? a : b;
}

// 최대 제곱수 찾는 함수
int get_max(int y, int x) {
    int max = -1;

    for(int y_sub = 0; y_sub < n; y_sub++) {
        for(int x_sub = 0; x_sub < m; x_sub++) {
            max = return_big(max, get_num(y, x, y_sub, x_sub));
            max = return_big(max, get_num(y, x, -y_sub, -x_sub));
            max = return_big(max, get_num(y, x, y_sub, -x_sub));
            max = return_big(max, get_num(y, x, -y_sub, x_sub));
        }
    }

    return max;
}

// 특정 좌표, 행과 열 좌표의 공차를 입력받음
// 공차를 기반으로 배열의 범위 내에서 나올 수 있는 모든 정수값 찾음 + 최대 제곱수 리턴
int get_num(int row, int column, int row_sub, int column_sub) {
    int max = -1;
    int tmp_num = arr[row][column];
    max = return_big(max, check_square(arr[row][column]));

    if(row_sub == 0 && column_sub == 0) return max;

    int cur_row = row + row_sub;
    int cur_column = column + column_sub;

    while(cur_row >= 0 && cur_row < n && cur_column >= 0 && cur_column < m) {
        tmp_num = tmp_num * 10 + arr[cur_row][cur_column];
        max = return_big(max, check_square(tmp_num));
        cur_row += row_sub;
        cur_column += column_sub;
    }

    return max;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string row;
    int res = -1;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> row;
        for(int j = 0; j < m; j++) {
            arr[i][j] = row[j] - '0';
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            res = return_big(res, get_max(i, j));
        }
    }

    cout << res << "\n";

    return 0;
}