import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[][] like = new int[N][M];
        for(int i=0;i<N;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<M;j++){
                like[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int ans = 0;
        // 조합 3개 선택
        for(int i=0;i<M-2;i++){
            for(int j=i+1;j<M-1;j++){
                for(int k=j+1;k<M;k++){
                    int sum = 0;
                    for(int u=0;u<N;u++){
                        sum += Math.max(like[u][i], Math.max(like[u][j], like[u][k]));
                    }
                    ans = Math.max(ans, sum);
                }
            }
        }
        System.out.println(ans);
    }
}
