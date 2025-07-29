import java.util.*;

public class BOJ14502 {
    static int N, M;
    static int[][] lab;
    static int maxSafe = 0;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        lab = new int[N][M];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                lab[i][j] = sc.nextInt();

        makeWall(0);
        System.out.println(maxSafe);
    }

    static void makeWall(int count) {
        if (count == 3) {
            spreadVirus();
            return;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (lab[i][j] == 0) {
                    lab[i][j] = 1;
                    makeWall(count + 1);
                    lab[i][j] = 0;
                }
            }
        }
    }

    static void spreadVirus() {
        int[][] copy = new int[N][M];
        for (int i = 0; i < N; i++) copy[i] = lab[i].clone();

        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (copy[i][j] == 2) q.offer(new int[]{i, j});

        while (!q.isEmpty()) {
            int[] now = q.poll();
            int x = now[0], y = now[1];

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                    if (copy[nx][ny] == 0) {
                        copy[nx][ny] = 2;
                        q.offer(new int[]{nx, ny});
                    }
                }
            }
        }

        int safe = 0;
        for (int[] row : copy)
            for (int val : row)
                if (val == 0) safe++;

        maxSafe = Math.max(maxSafe, safe);
    }
}
