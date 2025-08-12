import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class num_20115 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        double [] drinks = new double[N];
        for(int i=0;i<N;i++){
            drinks[i] = Double.parseDouble(st.nextToken());
        }
        Arrays.sort(drinks);
        for(int i=0;i<N-1;i++){
            drinks[i] /= 2;
        }
        for(int i=0;i<N-1;i++){
            drinks[N-1] += drinks[i];
        }
        System.out.println(drinks[N-1]);
    }
}
