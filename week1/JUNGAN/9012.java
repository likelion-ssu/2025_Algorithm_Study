import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            String s = br.readLine();
            int left = 0;
            String isVPS;
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == '(') {
                    left++;
                } else if (s.charAt(j) == ')') {
                    left--;
                }
                if(left<0){
                    break;
                }
            }
            if(left!=0) isVPS = "NO";
            else isVPS = "YES";
            System.out.println(isVPS);
        }
    }
}
