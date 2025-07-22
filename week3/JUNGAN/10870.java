import java.util.Scanner;

public class Main{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] list = new int[n+1];
        list[0] = 0;
        if(n>0) list[1] = 1;

        for(int i = 2; i <= n; i++){
            list[i] = list[i-1] + list[i-2];
        }

        System.out.println(list[n]);
    }
}