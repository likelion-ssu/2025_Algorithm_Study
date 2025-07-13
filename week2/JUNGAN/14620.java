import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class num_14620{
    static int min = Integer.MAX_VALUE;
    static int [][] prices;
    static boolean[][] visited;
    static int N;
    static int [] x = new int [] {0,1,-1,0,0};
    static int [] y = new int [] {0,0,0,1,-1};

    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        prices = new int[N][N];
        visited = new boolean[N][N];

        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++){
                prices[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dfs(0,0);
        System.out.println(min);

    }

    static void dfs(int cnt, int sum){
        if(cnt==3){
            min = Math.min(min,sum);
            return;
        }

        for(int i = 1;i<(N-1);i++){
            for(int j = 1;j<(N-1);j++){
                if(canPlace(i,j)){
                    int temp = placeFlower(i,j,true);
                    dfs(cnt+1,sum+temp);
                    placeFlower(i,j,false);
                }
            }
        }
    }

    static boolean canPlace(int i , int j){
        for(int k = 0; k<5 ;k++){
            if(visited[i+x[k]][j+y[k]]){return false;}
        }
        return true;
    }

    static int placeFlower(int i, int j, boolean state){
        for(int k = 0; k<5 ;k++){
            visited[i+x[k]][j+y[k]] = state;
        }
        int tempSum = 0;
        for(int k = 0; k<5 ;k++){
            tempSum += prices[i+x[k]][j+y[k]];
        }
        return tempSum;
    }


}
