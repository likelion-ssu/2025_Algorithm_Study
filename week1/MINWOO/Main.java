package MINWOO;
import java.io.*;             // 입력을 위한 패키지
import java.util.*;           // Stack, StringTokenizer 등을 위해

public class Main {
    public static void main(String[] args) throws IOException {
        // 입력을 빠르게 받기 위한 BufferedReader 선언
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 출력 속도를 높이기 위한 StringBuilder 사용
        StringBuilder sb = new StringBuilder();
        // 정수형 스택 생성
        Stack<Integer> stack = new Stack<>();

        // 첫 줄에 입력될 명령어의 수 n
        int n = Integer.parseInt(br.readLine());

        // n번 명령어 처리 반복
        while (n-- > 0) {
            // 명령어를 공백 기준으로 분리하여 배열로 저장
            String[] cmd = br.readLine().split(" ");

            // 명령어 종류에 따라 분기 처리
            switch (cmd[0]) {
                case "push":
                    // push X: 정수 X를 스택에 추가
                    stack.push(Integer.parseInt(cmd[1]));
                    break;

                case "pop":
                    // pop: 스택이 비어있으면 -1, 아니면 top 제거 후 출력
                    sb.append(stack.isEmpty() ? -1 : stack.pop()).append("\n");
                    break;

                case "size":
                    // size: 스택에 들어 있는 정수 개수 출력
                    sb.append(stack.size()).append("\n");
                    break;

                case "empty":
                    // empty: 스택이 비어있으면 1, 아니면 0 출력
                    sb.append(stack.isEmpty() ? 1 : 0).append("\n");
                    break;

                case "top":
                    // top: 스택의 가장 위에 있는 정수 출력, 없으면 -1
                    sb.append(stack.isEmpty() ? -1 : stack.peek()).append("\n");
                    break;
            }
        }

        // StringBuilder에 누적된 출력 결과를 한 번에 출력
        System.out.print(sb);
    }
}
