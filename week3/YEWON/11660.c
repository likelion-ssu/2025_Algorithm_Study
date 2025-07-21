#include <stdio.h>

int arr[1025][1025];

int main() {
    int N, M;
    int x1, y1, x2, y2;

    scanf("%d %d", &N, &M);
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    //행 기준으로 부분합 구하기
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            arr[i][j] = arr[i][j] + arr[i-1][j];
        }
    }

    // 열 기준으로 부분합 구하기
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            arr[i][j] = arr[i][j] + arr[i][j-1];
        }
    }

    for(int k = 0; k < M; k++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", arr[x2][y2] - arr[x1-1][y2] - arr[x2][y1-1] + arr[x1-1][y1-1]);
    }
    return 0;
}