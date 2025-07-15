#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** arr;
bool** isVisited;
int N;
int answer = 987654321;

bool checkPosition(int i, int j) {
    if (!isVisited[i][j] && !isVisited[i+1][j] && !isVisited[i-1][j] &&
        !isVisited[i][j+1] && !isVisited[i][j-1]) {
        return true;
    }
    return false;
}

void set(int i, int j, bool b) {
    isVisited[i][j] = b;
    isVisited[i+1][j] = b;
    isVisited[i-1][j] = b;
    isVisited[i][j+1] = b;
    isVisited[i][j-1] = b;
}

void backTracking(int depth, int maxDepth) {
    if (depth == maxDepth) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (isVisited[i][j]) {
                    sum += arr[i][j];
                }
            }
        }
        if (sum < answer)
            answer = sum;
    } else {
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < N - 1; j++) {
                if (checkPosition(i, j)) {
                    set(i, j, true);
                    backTracking(depth + 1, maxDepth);
                    set(i, j, false);
                }
            }
        }
    }
}

int main() {
    scanf("%d", &N);

    arr = (int**)malloc(N * sizeof(int*));
    isVisited = (bool**)malloc(N * sizeof(bool*));
    for (int i = 0; i < N; i++) {
        arr[i] = (int*)malloc(N * sizeof(int));
        isVisited[i] = (bool*)malloc(N * sizeof(bool));
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
            isVisited[i][j] = false;
        }
    }

    backTracking(0, 3);

    printf("%d\n", answer);

    for (int i = 0; i < N; i++) {
        free(arr[i]);
        free(isVisited[i]);
    }
    free(arr);
    free(isVisited);

    return 0;
}