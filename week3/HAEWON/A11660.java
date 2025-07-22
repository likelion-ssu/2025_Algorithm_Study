import java.util.Scanner;

public class A11660 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt(); // 표 크기
        int m = sc.nextInt();
        int[][] map = new int[size + 1][size + 1]; // 입력 표
        int[][] sum = new int[size + 1][size + 1]; // 누적합용 배열

        // 계산
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                map[i][j] = sc.nextInt();
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + map[i][j];
            }
        }

        StringBuilder sb = new StringBuilder();

        // 쿼리 처리
        for (int q = 0; q < m; q++) {
            int x1 = sc.nextInt();
            int y1 = sc.nextInt();
            int x2 = sc.nextInt();
            int y2 = sc.nextInt();

            int mSum = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
            sb.append(mSum).append("\n");
        }
        System.out.print(sb);
    }
}
