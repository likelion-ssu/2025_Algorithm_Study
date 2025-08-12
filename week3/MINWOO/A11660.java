import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();  // 배열 크기
        int M = sc.nextInt();  // 질의 개수

        int[][] arr = new int[N + 1][N + 1]; // 실제 데이터 저장 (1번부터 쓰려고 +1)
        int[][] sum = new int[N + 1][N + 1]; // 누적합 저장 배열

        // 원래 값 입력 받기
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        // 누적합 배열 만들기 (기준: 왼쪽, 위, 대각선)
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
            }
        }

        // 질의마다 정해진 범위 합 출력
        for (int t = 0; t < M; t++) {
            int x1 = sc.nextInt();
            int y1 = sc.nextInt();
            int x2 = sc.nextInt();
            int y2 = sc.nextInt();

            // 누적합 공식을 써서 해당 구간만 잘라서 구함
            int result = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];

            System.out.println(result);
        }
    }
}

/* 목표: 2차원 배열에서 **(x1,y1) ~ (x2,y2)**의 합을 빠르게 구하자.
누적합을 써서 처리 속도를 빠르게 하기? 거리 */ 
