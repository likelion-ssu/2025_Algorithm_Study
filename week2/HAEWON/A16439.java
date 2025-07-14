import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A16439 {
    static int n,m;
    static int[][] likes;
    static int maxSum = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        likes = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                likes[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        selectChicken(new int[3], 0, 0);

        System.out.println(maxSum);
    }

    // 3가지 치킨 종류 조합 고르는 재귀 함수
    static void selectChicken(int[] selected, int start, int depth) {
        if (depth == 3) {
            int total = calc(selected);
            maxSum = Math.max(maxSum, total);
            return;
        }

        for (int i = start; i < m; i++) {
            selected[depth] = i;
            selectChicken(selected, i + 1, depth + 1);
        }
    }

    // 선택된 치킨 종류에 대해 회원 만족도 합 계산
    static int calc(int[] selected) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int best = 0;
            for (int c : selected) {
                if (likes[i][c] > best) best = likes[i][c];
            }
            sum += best;
        }
        return sum;
    }
}
