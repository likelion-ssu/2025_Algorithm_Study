import java.util.Scanner;

public class num_2294 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int [] coins = new int[n];
        for(int i = 0; i < n; i++) {
            coins[i] = sc.nextInt();
        }

        int[] dp = new int[k+1];
        for(int i = 0; i < k+1; i++) {
            dp[i] = k+1;
        }
        dp[0] = 0;
        for(int i = 1; i <= k; i++) {
            for(int j = 0; j < coins.length; j++) {
                if(i >= coins[j]) {
                    dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);}
            }
        }

        System.out.println(dp[k] == k+1 ? -1 : dp[k]);
    }
}