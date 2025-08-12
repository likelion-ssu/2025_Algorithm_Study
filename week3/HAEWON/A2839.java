import java.util.Scanner;

public class A2839 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sugar = sc.nextInt(); // 총 설탕 무게
        int n = sugar / 5; // 5kg 최대 개수
        int left = sugar % 5; // 남은 무게

        while (n >= 0) {
            if (left % 3 == 0) {
                int m = left / 3; // 3kg 개수
                System.out.println(n + m);
                return;
            }
            n--;
            left = sugar - n * 5; // 남은 무게 다시 계산
        }

        System.out.println(-1); // 정확하게 Nkg을 만들 수 없을때
    }
}
