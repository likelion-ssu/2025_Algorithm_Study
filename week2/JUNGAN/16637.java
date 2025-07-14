import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class num_16637 {
    static int N;
    static int max = Integer.MIN_VALUE;
    static int [] num;
    static char [] op;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        num = new int[(N+1)/2];
        op = new char[(N-1)/2];
        String st = br.readLine();
        num[0] = Integer.parseInt(st.charAt(0)+"");
        for(int i=0;i<(N-1)/2;i++){
            op[i] = st.charAt(i*2+1);
            num[i+1] = Integer.parseInt(st.charAt(i*2+2)+"");
        }

        dfs(0,num[0]); // 맨 처음 왼쪽 값 num[0]
        System.out.println(max);
    }

    static void dfs(int index, int sum){
        int temp; // dfs에 넘길 이때까지 계산된 sum 값
        if(index>= op.length){
            max = Math.max(max,sum);
            return;
        }

        //괄호 없이 다음 연산 -> 바로 계산하고 다음 dfs 불러오면 됨.
        //이때까지 계산한 값을 sum으로 전달받고 연산 후 또 전달
        temp = calc(sum, num[index+1],op[index]);
        dfs(index+1, temp);

        //괗호 추가해서 연산 할 수 있는 경우 -> index가 op.length - 2 까지만
        //index + 1 연산을 먼저 하고 그걸 calc의 m에 넣어준다.
        if(index <=op.length-2){
            int value = calc(num[index+1],num[index+2],op[index+1]);//index + 1 연산
            temp = calc(sum,value,op[index]);
            dfs(index+2, temp); //index, index + 1 계산 이미 했으므로 index + 2 해야함.
        }
    }

    static int calc(int n, int m, char op){
//        switch(op){
//            case '+':
//                return n + m;
//                break;
//            case '-':
//                return n - m;
//                break;
//            case '*':
//                return n * m;
//                break;
//        }
        if(op == '+'){
            return n+m;
        }else if(op == '-'){
            return n-m;
        }else{
            return n*m;
        }
    }
}
