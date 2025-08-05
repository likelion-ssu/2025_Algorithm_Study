import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class num_13975 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int i = 0; i < T; i++) {
            int K = Integer.parseInt(br.readLine());
            PriorityQueue<Long> pq = new PriorityQueue<Long>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < K; j++) {
                pq.add(Long.parseLong(st.nextToken()));
            }
            long sum = 0;
            for(int j = 0; j < K-1; j++) {
                long temp = pq.poll() + pq.poll();
                sum += temp;
                pq.add(temp);
            }
            System.out.println(sum);
        }
    }
}
