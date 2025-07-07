import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Deque<Integer> q = new ArrayDeque<>();
        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        while (n-- > 0) {
            String[] cmd = br.readLine().split(" ");
            switch (cmd[0]) {
                case "push": q.offer(Integer.parseInt(cmd[1])); break;
                case "pop": sb.append(q.isEmpty() ? -1 : q.poll()).append("\n"); break;
                case "size": sb.append(q.size()).append("\n"); break;
                case "empty": sb.append(q.isEmpty() ? 1 : 0).append("\n"); break;
                case "front": sb.append(q.isEmpty() ? -1 : q.peek()).append("\n"); break;
                case "back": sb.append(q.isEmpty() ? -1 : ((ArrayDeque<Integer>) q).peekLast()).append("\n"); break;
            }
        }
        System.out.print(sb);
    }
}
