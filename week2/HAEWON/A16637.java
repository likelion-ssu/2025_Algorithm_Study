import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class A16637 {
    static ArrayList<Integer> num;   // 숫자들
    static ArrayList<Character> op;  // 연산자들
    static int best = Integer.MIN_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();

        num = new ArrayList<>();
        op  = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (i % 2 == 0) num.add(c - '0');
            else op.add(c);
        }

        dfs(num.get(0), 0);           // 0번 연산자부터
        System.out.println(best);
    }

    /* a (op) b */
    static int calc(int a, int b, char o) {
        if (o == '+') return a + b;
        if (o == '-') return a - b;
        return a * b;
    }

    static void dfs(int result, int idx) {
        if (idx >= op.size()) {               // 연산자 끝
            best = Math.max(best, result);
            return;
        }

        // 괄호 X
        int next = calc(result, num.get(idx + 1), op.get(idx));
        dfs(next, idx + 1);

        // 2) 괄호 O
        if (idx + 1 < op.size()) {
            int inside = calc(num.get(idx + 1), num.get(idx + 2), op.get(idx + 1));
            int combined = calc(result, inside, op.get(idx));
            dfs(combined, idx + 2);
        }
    }
}
