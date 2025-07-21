#include <stdio.h>

int main() {
    int N, result;
    scanf("%d", N);

    while(N > 0) {
        if(N % 5 == 0) {
            result += 1;
            N -= 5;
        } else {
            result += 1;
            N -= 3;
        }
    }
    if (N != 0 || result == 0) {
        printf("-1/n");
    } else {
        printf("%d", result);
    }
}