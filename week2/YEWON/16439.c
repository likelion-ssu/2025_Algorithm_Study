#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int max3(int a, int b, int c) {
    return max(a, max(b, c));
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int like[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &like[i][j]);
        }
    }

    int maxSum = 0;

    for (int a = 0; a < m; a++) {
        for (int b = a + 1; b < m; b++) {
            for (int c = b + 1; c < m; c++) {
                int tmpSum = 0;
                for (int i = 0; i < n; i++) {
                    tmpSum += max3(like[i][a], like[i][b], like[i][c]);
                }
                if (tmpSum > maxSum) {
                    maxSum = tmpSum;
                }
            }
        }
    }

    printf("%d\n", maxSum);
    return 0;
}