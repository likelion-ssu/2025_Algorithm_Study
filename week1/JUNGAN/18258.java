import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        IntQueue que = new IntQueue(N);

        StringBuilder builder = new StringBuilder();

        for (int i = 0; i < N; i++) {
            String s = br.readLine();
            if(s.startsWith("push")) {
                String[] list = s.split(" ");
                que.push(Integer.parseInt(list[1]));
            }
            else if(s.equals("pop")) {
                builder.append(que.pop() + "\n");
            }
            else if(s.equals("size")) {
                builder.append(que.size() + "\n");
            }
            else if(s.equals("empty")) {
                builder.append(que.isEmpty() ? 1 : 0).append("\n"); // 연산자 우선순위 문제
            }
            else if(s.equals("front")) {
                builder.append(que.front() + "\n");
            }
            else if(s.equals("back")) {
                builder.append(que.back() + "\n");
            }

        }
        System.out.println(builder);
    }
}

class IntQueue {
    int [] que;
    int size;
    int capacity;
    int front, rear;

    public IntQueue(int capacity) {
        this.capacity = capacity;
        size = front = rear = 0;
        que = new int[capacity];
    }

    void push(int x) {
        size++;
//        que[rear++] = x;
//        if (rear == capacity) rear = 0;
        que[rear] = x;
        rear = (rear + 1) % capacity;
    }

    int pop() {
        if (size == 0) return -1;
        size--;
        int k = que[front++];
        if (front == capacity) front = 0;
        return k;
    }

    int size(){
        return size;
    }

    boolean isEmpty(){
        return size == 0;
    }

    int front(){
        if (size == 0) return -1;
        return que[front];
    }

    int back(){
        if (size == 0) return -1;
        else if (rear - 1 < 0) return que[capacity - 1 ];
        return que[rear-1];
    }
}