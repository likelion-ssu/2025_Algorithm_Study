import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class A7576 {
    static int M, N;
    static int[][] box;
    static int[][] days;
    static Queue<int[]> queue = new LinkedList<>();

    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        M = sc.nextInt(); // 가로
        N = sc.nextInt(); // 세로
        box = new int[N][M];
        days = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                box[i][j] = sc.nextInt();
                if (box[i][j] == 1) {
                    queue.add(new int[]{i, j}); // 익은 토마토들 BFS 시작점
                }
            }
        }

        bfs();

        int max = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                // 안 익은 토마토가 남아있다면
                if (box[i][j] == 0) {
                    System.out.println(-1);
                    return;
                }
                max = Math.max(max, days[i][j]); // 최대 일수
            }
        }

        System.out.println(max);
    }

    static void bfs() {
        while (!queue.isEmpty()) {
            int[] now = queue.poll();
            int x = now[0];
            int y = now[1];

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // 범위 벗어나면 무시
                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                // 익지 않은 토마토면 익히고 큐에 추가
                if (box[nx][ny] == 0) {
                    box[nx][ny] = 1; // 익힘 표시
                    days[nx][ny] = days[x][y] + 1; // 일수 누적
                    queue.add(new int[]{nx, ny});
                }
            }
        }
    }
}
