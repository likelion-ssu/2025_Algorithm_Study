import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  // 입력 받기 위한 Scanner 생성
        int N = sc.nextInt();                 // 배달해야 할 설탕 무게 (kg)
        
        int count = 0;                        // 봉지 개수를 셀 변수

        // 5kg 봉지를 최대한 써보고, 안되면 3kg으로 바꾸는 방식
        while (N >= 0) {
            if (N % 5 == 0) {                 // 5로 딱 나눠 떨어지면
                count += N / 5;               // 5kg 봉지 개수 더해주고
                System.out.println(count);    // 정답 출력
                return;                       // 프로그램 종료
            }
            N -= 3;                           // 5로 안 나눠 떨어지면 3kg 하나 써보고
            count++;                          // 봉지 개수 하나 추가
        }

        // 여기까지 왔다는 건 정확히 안 나눠졌다는 뜻
        System.out.println(-1);              // 정확히 배달 못 함
    }
}

/*
목표: 설탕 Nkg을 5kg, 3kg 봉지로 나눠서 최소 봉지 수로 배달하는 법 찾기
단, 정확히 Nkg 맞춰야 함. 
*/
