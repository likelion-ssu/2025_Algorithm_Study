/* 상향식이 아닌 하향식으로 문제를 접근해야 하는 이유 */

// 상향식
// 2를 곱하거나 10배하고 1을 더하는 두 개의 선택지에 대해서
// 단계가 커질수록 경우의 수가 2배씩 커짐. 도달하는 단계가 5단계라고 하면 첫 단계 제외하고 2의 4승의 경우의 수 발생
// 시간복잡도 : O(2^n) ?

// 하향식
// 매 단계에서 전 단계로 되돌리는 선택지가 숫자에 따라 한 가지임
// 짝수라면 이전 단계에서 2배를 한 것이기 때문에 2로 나눠줌
// 끝의 자리가 1이면 1을 빼고 10으로 나눠줌.
// 그러다가 짝수도 아니고, 끝의 자리가 1도 아니면 끝


import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long A = sc.nextLong(); // 시작 숫자
        long B = sc.nextLong(); // 목표 숫자
        int count = 1; // 연산 횟수 (시작도 포함이래서 1로 시작)

        while (B != A) {
            if (B < A) { // 도중에 작아지면 끝임
                count = -1;
                break;
            }

            if (B % 10 == 1) {
                B /= 10; // 끝자리가 1이면 10으로 나눠서 되돌리기
            } else if (B % 2 == 0) {
                B /= 2; // 짝수면 2로 나누기
            } else {
                count = -1; // 둘 다 아니면 절대 못 만듦
                break;
            }

            count++; // 연산 하나 했으니까 +1
        }

        System.out.println(count);
    }
}
