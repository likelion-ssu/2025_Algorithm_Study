import java.util.Scanner;

public class num_14916 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // 5원을 최대한 많이 쓰고
        int five = n / 5;
        while (five >= 0) {
            int remain = n - (5 * five);
            if (remain % 2 == 0) {
                int two = remain / 2;
                System.out.println(five + two);
                return;
            }
            five--; // 5원을 하나 줄여서 다시 시도
        }

        // 못 만들면
        System.out.println(-1);
    }
}
