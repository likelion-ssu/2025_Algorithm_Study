import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        IntStack stake = new IntStack(10000);
        int N = sc.nextInt();

        for (int i = 0; i < N; i++) {
            String s = sc.next();
            switch (s) {
                case "push":
                    stake.push(sc.nextInt());
                    break;
                case "pop":
                    System.out.println(stake.pop());
                    break;
                case "size":
                    System.out.println(stake.size());
                    break;
                case "empty":
                    if (stake.isEmpty()) System.out.println("1");
                    else System.out.println("0");
                    break;
                case "top":
                    System.out.println(stake.top());
                    break;
            }
        }
    }
}

class IntStack {
    int[] stack;
    int size;
    int ptr;

    IntStack(int size) {
        ptr = 0;
        this.size = size;
        stack = new int[size];
    }

    void push(int x) {
        stack[ptr++] = x;
    }

    int pop() {
        if(this.isEmpty()) return -1;
        return stack[--ptr];
    }

    int size(){
        return ptr;
    }

    boolean isEmpty(){
        return ptr == 0;
    }

    int top(){
        if(this.isEmpty()){
            return -1;
        }
        return stack[ptr-1];
    }
}