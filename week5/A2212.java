import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt(); // 센서 개수
        int K = sc.nextInt(); // 집중국 개수

        int[] sensors = new int[N];
        for (int i = 0; i < N; i++) {
            sensors[i] = sc.nextInt();
        }

        Arrays.sort(sensors); // 위치 정렬

        // 센서 사이 거리 배열
        int[] gaps = new int[N - 1];
        for (int i = 0; i < N - 1; i++) {
            gaps[i] = sensors[i + 1] - sensors[i]; // 인접 센서 거리 차이
        }

        Arrays.sort(gaps); // 거리 차이를 정렬

        int result = 0;
        // 큰 거리부터 끊으면 됨 (K-1개 끊기)
        for (int i = 0; i < N - K; i++) {
            result += gaps[i]; // 작은 거리부터 더하기
        }

        System.out.println(result);
    }
}
