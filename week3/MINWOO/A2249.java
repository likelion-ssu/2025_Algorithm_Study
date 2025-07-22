import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt(); // 동전 종류 수
        int K = sc.nextInt(); // 만들어야 할 금액

        int[] coin = new int[N]; // 동전 종류 저장 배열

        for (int i = 0; i < N; i++) {
            coin[i] = sc.nextInt(); // 동전 값 입력
        }

        int[] dp = new int[K + 1]; // dp[i] = i원을 만들기 위한 최소 동전 수
        Arrays.fill(dp, 10001);    // 처음엔 다 불가능한 값으로 채워놓기
        dp[0] = 0;                 // 0원은 동전 0개로 만들 수 있음

        // 각 동전으로 만들 수 있는 경우 다 계산해보기
        for (int i = 0; i < N; i++) {
            for (int j = coin[i]; j <= K; j++) {
                // 현재 j원을 만들기 위한 최소값 갱신
                dp[j] = Math.min(dp[j], dp[j - coin[i]] + 1);
            }
        }

        // 정답 출력
        if (dp[K] == 10001) {
            System.out.println(-1); // 못 만드는 경우
        } else {
            System.out.println(dp[K]); // 최소 동전 개수 출력
        }
    }
}

/*
목표: 정해진 동전으로 정확히 K원을 만들 때 필요한 최소 동전 수를 구하자
중복 사용 가능, 순서는 상관 없음.
*/
