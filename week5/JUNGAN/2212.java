import java.util.Arrays;
import java.util.Scanner;

public class num_2212 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sensorNum = sc.nextInt();
        int head = sc.nextInt();
        int[] sensors = new int[sensorNum];
        for (int i = 0; i < sensorNum; i++) {
            sensors[i] = sc.nextInt();
        }

        Arrays.sort(sensors);
        int[] sensorDistance = new int[sensorNum-1];
        for(int i = 0; i < sensorDistance.length; i++) {
            sensorDistance[i] = sensors[i+1] - sensors[i];
        }
        Arrays.sort(sensorDistance);

        int sum = 0;
        for(int i = 0; i < sensorDistance.length - (head-1); i++) {
            sum += sensorDistance[i];
        }
        System.out.println(sum);
    }
}
