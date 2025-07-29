import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class A2667 {
    static int N;
    static int[][] map;
    static boolean[][] visited;
    static List<Integer> complexSizes = new ArrayList<>();

    // 상하좌우 이동
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    // DFS로 단지 탐색
    static int dfs(int x, int y) {
        visited[x][y] = true;
        int count = 1; // 현재 집도 포함

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 지도 범위 벗어나면 무시
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;

            // 집이 있고 아직 방문 안 했으면 재귀
            if (map[nx][ny] == 1 && !visited[nx][ny]) {
                count += dfs(nx, ny);
            }
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        sc.nextLine(); // 개행 문자 제거

        map = new int[N][N];
        visited = new boolean[N][N];

        // 지도 입력
        for (int i = 0; i < N; i++) {
            String line = sc.nextLine();
            for (int j = 0; j < N; j++) {
                map[i][j] = line.charAt(j) - '0';
            }
        }

        // 단지 찾기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    int size = dfs(i, j);
                    complexSizes.add(size);
                }
            }
        }

        // 결과 출력
        Collections.sort(complexSizes);
        System.out.println(complexSizes.size());
        for (int size : complexSizes) {
            System.out.println(size);
        }
    }
}
