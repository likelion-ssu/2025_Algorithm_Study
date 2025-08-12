// 문자열 집합 문제
// 아이디어: N개의 문자열을 저장해두고, M개의 문자열이 그 안에 있는지 확인

import java.io.*;
import java.util.*;

public class BOJ14425 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        StringTokenizer st = new StringTokenizer(br.readLine()); // 첫 줄 나누기

        int N = Integer.parseInt(st.nextToken()); // 집합에 넣을 문자열 수
        int M = Integer.parseInt(st.nextToken()); // 검사할 문자열 수

        HashSet<String> set = new HashSet<>(); // 문자열을 저장

        // N개의 문자열 입력받아 저장
        for (int i = 0; i < N; i++) {
            set.add(br.readLine()); // 한 줄 읽어서 추가
        }

        int count = 0; // 결과를 셀 변수

        // M개의 문자열 각각 검사
        for (int i = 0; i < M; i++) {
            String word = br.readLine();
            if (set.contains(word)) { // set 안에 있으면
                count++; // 개수 증가
            }
        }

        System.out.println(count); // 최종 개수 출력
    }
}
