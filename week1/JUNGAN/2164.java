import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int [] deque = new int[N];
        int front = 0;
        int back = 0;

        for (int i = 1; i < N+1; i++) {
            deque[i-1] = i;
        }

        for(int i = 0; i < N-1; i++){
            front = (front + 1) % N;
            deque[back] = deque[front];
            back = (back + 1) % N;
            front = (front + 1) % N;
        }


        System.out.println(deque[front]);
    }
}
