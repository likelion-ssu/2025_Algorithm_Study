import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class num_2839 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] dp = new int[N + 1];

        Arrays.fill(dp, 5001);  // 최대치로 초기화 (불가능한 상태 의미)
        dp[0] = 0; // 0kg일 때 봉지 0개

        for (int i = 3; i <= N; i++) {
            if (i >= 3) dp[i] = Math.min(dp[i], dp[i - 3] + 1);
            if (i >= 5) dp[i] = Math.min(dp[i], dp[i - 5] + 1);
        }

        System.out.println(dp[N] == 5001 ? -1 : dp[N]);

    }
}
