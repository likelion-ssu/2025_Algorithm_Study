import java.util.Scanner;

public class num_16953 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int count = 0;

        while (B>=A){
            if(B%2==0){
                B = B/2;
                count++;
            }
            else if(B%10 == 1) {
                B = B/10;
                count++;
            }
            else{
                System.out.println(-1);
                return;
            }
            if(B==A) {
                System.out.println(count+1);
                return;
            }
        }
        System.out.println(-1);
    }
}
