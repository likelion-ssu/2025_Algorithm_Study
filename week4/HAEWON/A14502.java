import java.util.*;

public class A14502 {
    static int N, M;
    static int[][] lab;
    static int maxSafe = 0;
    static List<int[]> viruses = new ArrayList<>();

    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt(); // 세로
        M = sc.nextInt(); // 가로
        lab = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                lab[i][j] = sc.nextInt();
                if (lab[i][j] == 2) {
                    viruses.add(new int[]{i, j});
                }
            }
        }

        dfs(0); // 벽 3개 세우는 모든 경우 탐색
        System.out.println(maxSafe);
    }

    // 벽 3개 세우기
    static void dfs(int depth) {
        if (depth == 3) {
            bfs(); // 벽 세운 뒤 바이러스 퍼뜨리기
            return;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (lab[i][j] == 0) {
                    lab[i][j] = 1;
                    dfs(depth + 1);
                    lab[i][j] = 0; // 되돌리기 (백트래킹)
                }
            }
        }
    }

    // 바이러스 퍼뜨리기 (BFS)
    static void bfs() {
        int[][] temp = new int[N][M];
        for (int i = 0; i < N; i++)
            temp[i] = lab[i].clone();

        Queue<int[]> queue = new LinkedList<>();
        for (int[] v : viruses) {
            queue.add(new int[]{v[0], v[1]});
        }

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int x = cur[0];
            int y = cur[1];

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                    if (temp[nx][ny] == 0) {
                        temp[nx][ny] = 2;
                        queue.add(new int[]{nx, ny});
                    }
                }
            }
        }

        countSafe(temp);
    }

    // 안전 구역 세기
    static void countSafe(int[][] map) {
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 0) count++;
            }
        }
        maxSafe = Math.max(maxSafe, count);
    }
}
