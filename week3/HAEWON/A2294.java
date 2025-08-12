import java.util.Arrays;
import java.util.Scanner;

public class A2294 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // 동전 종류
        int k = sc.nextInt(); // 총 합
        int[] coin = new int[n];

        for (int i = 0; i < n; i++) {
            coin[i] = sc.nextInt();
        }

        int[] min = new int[k + 1];
        Arrays.fill(min, Integer.MAX_VALUE);
        min[0] = 0;  // 0원 만들때 동전 0개 필요

        for (int i : coin) {
            for (int j = i; j <= k; j++) {
                if (min[j - i] != Integer.MAX_VALUE) {
                    min[j] = Math.min(min[j], min[j - i] + 1);
                }
            }
        }
        System.out.println(min[k] == Integer.MAX_VALUE ? -1 : min[k]);
    }
}
