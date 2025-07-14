import java.io.*;

public class Main {
    static int N, ans = Integer.MIN_VALUE;
    static char[] expr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        expr = br.readLine().trim().toCharArray();

        dfs(1, expr[0] - '0');  // 첫 숫자로 시작
        System.out.println(ans);
    }

    static void dfs(int idx, int value) {
        if(idx >= N) {
            ans = Math.max(ans, value);
            return;
        }
        // 1) 괄호 없이 연산
        int v1 = calc(value, expr[idx] - '0', expr[idx-1]);
        dfs(idx + 2, v1);

        // 2) 괄호 사용 (가능하면)
        if(idx + 2 < N) {
            int inside = calc(expr[idx] - '0', expr[idx+2] - '0', expr[idx+1]);
            int v2 = calc(value, inside, expr[idx-1]);
            dfs(idx + 4, v2);
        }
    }

    static int calc(int a, int b, char op) {
        switch(op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
        }
        return 0;
    }
}
