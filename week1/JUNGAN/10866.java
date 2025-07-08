import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        IntDeque deq = new IntDeque(10000);
        StringBuilder builder = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            String s = br.readLine();
            if(s.startsWith("push_front")) {
                deq.pushFront(Integer.parseInt(s.split(" ")[1]));
            }
            else if(s.startsWith("push_back")) {
                deq.pushBack(Integer.parseInt(s.split(" ")[1]));
            }
            else if(s.equals("pop_front")) {
                builder.append(deq.popFront()).append("\n");
            }
            else if(s.equals("pop_back")) {
                builder.append(deq.popBack()).append("\n");
            }
            else if(s.equals("size")) {
                builder.append(deq.size()).append("\n");
            }
            else if(s.equals("empty")) {
                builder.append(deq.isEmpty()?1:0).append("\n");
            }
            else if(s.equals("front")) {
                builder.append(deq.front()).append("\n");
            }
            else if(s.equals("back")) {
                builder.append(deq.back()).append("\n");
            }
        }
        System.out.println(builder);
    }


}

class IntDeque{
    int[] deque;
    int size, front, back, capacity;

    IntDeque(int capacity) {
        this.capacity = capacity;
        deque = new int[capacity];
        size = front = back = 0;
    }

    void pushFront(int x) {
        size++;
        front = (front - 1 + capacity) % capacity;
        deque[front] = x;
    }

    void pushBack(int x) {
        size++;
        deque[back] = x;
        back = (back + 1) % capacity;
    }

    int popFront() {
        if(size == 0) return -1;
        size--;
        int x = deque[front];
        front = (front + 1) % capacity;
        return x;
    }

    int popBack() {
        if(size == 0) return -1;
        size--;
        back = (back - 1 + capacity) % capacity;
        return deque[back];
    }

    int size(){
        return size;
    }

    boolean isEmpty(){
        return size == 0;
    }

    int front(){
        if(size == 0) return -1;
        return deque[front];
    }

    int back(){
        if(size == 0) return -1;
        return deque[(back - 1 +capacity) % capacity];
    }
}