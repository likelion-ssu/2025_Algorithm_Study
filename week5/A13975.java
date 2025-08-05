import java.util.Scanner;  
import java.util.PriorityQueue;  

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  // Scanner를 이용해 입력 받기
        int T = sc.nextInt();  // 테스트 케이스 수 입력 받기

        // 테스트 케이스 수만큼 반복
        for (int t = 0; t < T; t++) {
            int K = sc.nextInt();  // 파일의 개수 입력 받기

            // 우선순위 큐 생성 (작은 값이 먼저 나오는 Min Heap 구조)
            PriorityQueue<Long> pq = new PriorityQueue<>();

            // 파일 크기 입력 받고 큐에 저장
            for (int i = 0; i < K; i++) {
                long fileSize = sc.nextLong();  // 각 파일 크기를 long 타입으로 입력
                pq.offer(fileSize);  // 파일 크기를 큐에 추가
            }

            long totalCost = 0;  // 총 합치는 비용 저장 변수

            // 큐에 파일이 두 개 이상 있을 때까지 반복
            while (pq.size() > 1) {
                // 가장 작은 파일 두 개 꺼내기
                long first = pq.poll();  // 첫 번째로 작은 파일 꺼내기
                long second = pq.poll(); // 두 번째로 작은 파일 꺼내기

                long merged = first + second;  // 두 파일 합치기
                totalCost += merged;  // 합친 비용을 누적

                pq.offer(merged);  // 합친 파일을 큐에 다시 넣기
            }

            System.out.println(totalCost);  // 최종 최소 비용 출력
        }
    }
}
