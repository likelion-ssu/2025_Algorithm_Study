import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class num_16439 {
    static int max = 0;
    static int N;
    static int M;
    static int[][] stars;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        stars = new int[N][M];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++) {
                stars[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < M-2; i++) {
            for(int j = 1; j < M-1; j++) {
                for(int k = 2; k < M; k++) {
                    int sum = 0;
                    for(int l = 0; l < N; l++) {
                        sum += Math.max(Math.max(stars[l][i], stars[l][j]),stars[l][k]);
                    }
                    max = Math.max(max, sum);
                }
            }
        }
        System.out.println(max);
    }
}
