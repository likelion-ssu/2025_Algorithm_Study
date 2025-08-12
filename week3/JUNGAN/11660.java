import java.io.IOException;
import java.util.Scanner;

public class num_11660 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int [][] arr = new int[N+1][N+1];
        for(int i = 1; i < N+1; i++) {
            for(int j = 1; j < N+1; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        int[][] Xarr = new int[N+1][N+1];
        int[][] sum = new int[N+1][N+1];

        for(int i = 1; i < N+1; i++) {
            Xarr[1][i] = arr[1][i];
            for(int j = 2; j < N+1; j++) {
                Xarr[j][i] = Xarr[j-1][i]+arr[j][i];
            }
        }

        for(int i = 1; i < N+1; i++) {
            sum[i][1] = Xarr[i][1];
            for(int j = 2; j < N+1; j++) {
                sum[i][j] = sum[i][j-1]+Xarr[i][j];
            }
        }

        for(int i = 0; i<M; i++){
            int x1 = sc.nextInt();
            int y1 = sc.nextInt();
            int x2 = sc.nextInt();
            int y2 = sc.nextInt();
            System.out.println(sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]);
        }
    }
}
