#include <stdio.h>

int num[20];
char op[20];
int num_len = 0;
int op_len = 0;
int ret = -987654321;

int calc(char oper, int a, int b) {
    if (oper == '+') return a + b;
    else if (oper == '-') return a - b;
    else if (oper == '*') return a * b;
    return 0;
}

void go(int idx, int tot) {
    if (idx == num_len - 1) {
        if (tot > ret) ret = tot;
        return;
    }

    go(idx + 1, calc(op[idx], tot, num[idx + 1]));

    if (idx + 2 <= num_len - 1) {
        int n = calc(op[idx + 1], num[idx + 1], num[idx + 2]);
        go(idx + 2, calc(op[idx], tot, n));
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            scanf("%d", &num[num_len++]);
        } else {
            scanf(" %c", &op[op_len++]);
        }
    }

    go(0, num[0]);
    printf("%d\n", ret);

    return 0;
}