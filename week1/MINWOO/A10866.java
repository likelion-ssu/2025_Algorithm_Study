package MINWOO;
import java.io.*;              // 입력/출력 관련
import java.util.*;            // Deque, LinkedList 등 자료구조 사용

public class Main {
    public static void main(String[] args) throws IOException {
        // 빠른 입력을 위한 BufferedReader 선언
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 빠른 출력 누적을 위한 StringBuilder 선언
        StringBuilder sb = new StringBuilder();

        // 덱(Deque) 자료구조 선언 (양방향 삽입/삭제 지원)
        Deque<Integer> deque = new LinkedList<>();

        // 명령어 개수 입력 받기
        int n = Integer.parseInt(br.readLine());

        // n번 반복하여 명령어 처리
        while (n-- > 0) {
            // 입력 문자열을 공백 기준으로 나눔
            String[] cmd = br.readLine().split(" ");

            switch (cmd[0]) {
                case "push_front":
                    // 정수 X를 덱 앞쪽에 추가
                    deque.addFirst(Integer.parseInt(cmd[1]));
                    break;
                case "push_back":
                    // 정수 X를 덱 뒤쪽에 추가
                    deque.addLast(Integer.parseInt(cmd[1]));
                    break;
                case "pop_front":
                    // 덱이 비어있으면 -1, 아니면 앞에서 제거하고 값 출력
                    sb.append(deque.isEmpty() ? -1 : deque.removeFirst()).append("\n");
                    break;
                case "pop_back":
                    // 덱이 비어있으면 -1, 아니면 뒤에서 제거하고 값 출력
                    sb.append(deque.isEmpty() ? -1 : deque.removeLast()).append("\n");
                    break;
                case "size":
                    // 덱에 들어있는 요소 개수 출력
                    sb.append(deque.size()).append("\n");
                    break;
                case "empty":
                    // 덱이 비어 있으면 1, 아니면 0 출력
                    sb.append(deque.isEmpty() ? 1 : 0).append("\n");
                    break;
                case "front":
                    // 덱이 비어 있으면 -1, 아니면 앞쪽 값 출력
                    sb.append(deque.isEmpty() ? -1 : deque.peekFirst()).append("\n");
                    break;
                case "back":
                    // 덱이 비어 있으면 -1, 아니면 뒤쪽 값 출력
                    sb.append(deque.isEmpty() ? -1 : deque.peekLast()).append("\n");
                    break;
            }
        }

        // 결과 한 번에 출력
        System.out.print(sb);
    }
}
