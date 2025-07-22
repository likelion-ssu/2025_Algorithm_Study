import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class A14620 {
    static int n, minCost = Integer.MAX_VALUE;
    static int[][] cost;
    static int[] dx = {0, 0, 0, 1, -1};  // 중앙, 오른쪽, 왼쪽, 아래, 위
    static int[] dy = {0, 1, -1, 0, 0};  // 중앙, 오른쪽, 왼쪽, 아래, 위

    // 꽃을 심을 수 있는 위치 저장 리스트
    static ArrayList<Point> candidates = new ArrayList<>();
    static class Point {
        int x, y;
        Point(int x, int y){
            this.x = x; this.y = y;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        cost = new int[n][n];
        for(int i=0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0;j<n;j++){
                cost[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 가장자리 제외
        for(int i=1; i<n-1; i++){
            for(int j=1; j<n-1; j++){
                candidates.add(new Point(i, j));
            }
        }
        dfs(new Point[3], 0, 0);
        System.out.println(minCost);
    }

    static void dfs(Point[] selected, int start, int depth){
        if(depth == 3){
            if(check(selected))
                minCost = Math.min(minCost, getCost(selected));
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            selected[depth] = candidates.get(i);
            dfs(selected, i+1, depth+1);
        }
    }

    static boolean check(Point[] selected){
        boolean[][] isVisited = new boolean[n][n];
        for(Point p : selected){
            for(int d=0; d<5; d++){
                int nx = p.x + dx[d];
                int ny = p.y + dy[d];
                if(isVisited[nx][ny]) return false; // 겹칠때
                isVisited[nx][ny] = true;
            }
        }
        return true;
    }

    static int getCost(Point[] selected){
        int sum = 0;
        for(Point p : selected){
            for(int d=0; d<5; d++){
                sum += cost[p.x + dx[d]][p.y + dy[d]];
            }
        }
        return sum;
    }
}