import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int i = 0; i<T; i++){
            int N = sc.nextInt();
            int M = sc.nextInt();

            long top = 1;
            long bottom = 1;

            if(N>M/2) N = M - N;

            for(int j = 0; j < N; j++){
                top *= (M-j);
                bottom *= (N-j);
            }
            System.out.println(top/bottom);
        }
    }
}