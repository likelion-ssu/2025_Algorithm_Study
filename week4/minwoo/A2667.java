import java.util.*;

public class BOJ2667 {
    static int N;
    static int[][] map;
    static boolean[][] visited;
    static ArrayList<Integer> result = new ArrayList<>();
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        map = new int[N][N];
        visited = new boolean[N][N];

        for (int i = 0; i < N; i++) {
            String line = sc.next();
            for (int j = 0; j < N; j++) {
                map[i][j] = line.charAt(j) - '0';
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    result.add(bfs(i, j));
                }
            }
        }

        Collections.sort(result);
        System.out.println(result.size());
        for (int r : result) System.out.println(r);
    }

    static int bfs(int x, int y) {
        Queue<int[]> q = new LinkedList<>();
        visited[x][y] = true;
        q.offer(new int[]{x, y});
        int count = 1;

        while (!q.isEmpty()) {
            int[] now = q.poll();
            int cx = now[0], cy = now[1];

            for (int d = 0; d < 4; d++) {
                int nx = cx + dx[d];
                int ny = cy + dy[d];

                if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                    if (map[nx][ny] == 1 && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.offer(new int[]{nx, ny});
                        count++;
                    }
                }
            }
        }

        return count;
    }
}
