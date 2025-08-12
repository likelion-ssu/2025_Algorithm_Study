import java.io.*;
import java.util.*;

public class Main {
    static int n, ans = Integer.MAX_VALUE;
    static int[][] cost;
    static boolean[][] used;
    static int[] dx = {0, 1, 0, -1, 0}, dy = {1, 0, -1, 0, 0};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        cost = new int[n][n];
        used = new boolean[n][n];
        for(int i=0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0;j<n;j++){
                cost[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dfs(0, 0);
        System.out.println(ans);
    }

    static void dfs(int idx, int sum) {
        if(idx == 3) {  // 3송이 모두 심었으면
            ans = Math.min(ans, sum);
            return;
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<n-1;j++){
                if(canPlace(i, j)) {
                    int v = place(i, j, true);
                    dfs(idx+1, sum + v);
                    place(i, j, false);  // backtrack
                }
            }
        }
    }

    static boolean canPlace(int x, int y) {
        for(int d=0;d<5;d++){
            int nx = x + dx[d], ny = y + dy[d];
            if(used[nx][ny]) return false;
        }
        return true;
    }

    static int place(int x, int y, boolean flag) {
        int c = 0;
        for(int d=0;d<5;d++){
            int nx = x + dx[d], ny = y + dy[d];
            used[nx][ny] = flag;
            c += cost[nx][ny];
        }
        return c;
    }
}
