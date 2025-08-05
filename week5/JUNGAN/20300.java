import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class num_20300 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        long [] arr = new long[N];
        for(int i=0;i<N;i++){
            arr[i] = Long.parseLong(st.nextToken());
        }
        Arrays.sort(arr);
        long [] Ms;
        if(N%2==0){
            Ms = new long[N/2];
            for(int i=0;i<N/2;i++){
                Ms[i] = arr[N-1-i] + arr[i];
            }
        }else{
            Ms = new long[(N+1)/2];
            Ms[(N+1)/2 - 1] = arr[N-1];
            for(int i=0;i<(N-1)/2;i++){
                Ms[i] = arr[N-2-i] + arr[i];
            }
        }
        Arrays.sort(Ms);
        System.out.println(Ms[Ms.length-1]);
    }
}
