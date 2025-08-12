// 문제 추천 시스템 1

import java.io.*;
import java.util.*;

public class BOJ21939 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine()); // 초기 문제 개수

        // 정렬 규칙은 난이도 오름차순, 같으면 문제 번호 오름차순
        TreeSet<int[]> set = new TreeSet<>((a, b) -> {
            if (a[0] != b[0]) return a[0] - b[0];
            return a[1] - b[1];
        });

        // 문제 번호 -> 난이도 저장
        HashMap<Integer, Integer> levelMap = new HashMap<>();

        // 초기 문제 입력
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int P = Integer.parseInt(st.nextToken()); // 문제 번호
            int L = Integer.parseInt(st.nextToken()); // 난이도
            set.add(new int[]{L, P}); // TreeSet에 저장
            levelMap.put(P, L); // 맵에도 저장
        }

        int M = Integer.parseInt(br.readLine()); // 명령 개수

        StringBuilder sb = new StringBuilder(); // 결과 모아두기

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            String cmd = st.nextToken();

            if (cmd.equals("add")) {
                int P = Integer.parseInt(st.nextToken());
                int L = Integer.parseInt(st.nextToken());
                set.add(new int[]{L, P});
                levelMap.put(P, L);
            } else if (cmd.equals("recommend")) {
                int x = Integer.parseInt(st.nextToken());
                if (x == 1) {
                    sb.append(set.last()[1]).append('\n'); // 가장 어려운 문제
                } else {
                    sb.append(set.first()[1]).append('\n'); // 가장 쉬운 문제
                }
            } else if (cmd.equals("solved")) {
                int P = Integer.parseInt(st.nextToken());
                int L = levelMap.get(P); // 난이도 찾기
                set.remove(new int[]{L, P});
                levelMap.remove(P); // 맵에서도 제거
            }
        }

        System.out.print(sb.toString());
    }
}
