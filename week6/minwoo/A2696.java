// 중앙값 구하기
// 두 개의 힙 사용: maxHeap(작은 쪽), minHeap(큰 쪽)
// 홀수번째 입력마다 중앙값 출력

import java.io.*;
import java.util.*;

public class BOJ2696 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine()); // 테스트 케이스 개수

        for (int t = 0; t < T; t++) {
            int M = Integer.parseInt(br.readLine()); // 수의 개수

            sb.append((M + 1) / 2).append('\n'); // 중앙값 개수 출력

            PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder()); // 작은 절반
            PriorityQueue<Integer> minHeap = new PriorityQueue<>(); // 큰 절반

            int count = 0; // 10개씩 출력 관리

            StringTokenizer st = null;

            for (int i = 1; i <= M; i++) {
                if ((i - 1) % 10 == 0) {
                    st = new StringTokenizer(br.readLine());
                }
                int num = Integer.parseInt(st.nextToken());

                if (maxHeap.isEmpty() || num <= maxHeap.peek()) {
                    maxHeap.offer(num);
                } else {
                    minHeap.offer(num);
                }

                if (!maxHeap.isEmpty() && !minHeap.isEmpty() && maxHeap.peek() > minHeap.peek()) {
                    minHeap.offer(maxHeap.poll());
                    maxHeap.offer(minHeap.poll());
                }

                if (maxHeap.size() > minHeap.size() + 1) {
                    minHeap.offer(maxHeap.poll());
                } else if (minHeap.size() > maxHeap.size()) {
                    maxHeap.offer(minHeap.poll());
                }

                if (i % 2 == 1) {
                    sb.append(maxHeap.peek()).append(' ');
                    count++;
                    if (count % 10 == 0) sb.append('\n');
                }
            }

            if (count % 10 != 0) sb.append('\n');
        }

        System.out.print(sb.toString());
    }
}
