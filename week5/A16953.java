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
