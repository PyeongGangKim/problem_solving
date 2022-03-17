package 번1475;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int[] nums = new int[10];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String N = br.readLine();
        for(int i = 0 ; i < N.length() ; i++){
            nums[N.charAt(i) - '0']++;
        }
        int num = 0; int max = 0;
        for(int i = 0 ; i < 10 ; i++){
            if(i == 6 || i == 9) continue;
            if(nums[i] > max){
                num = i;
                max = nums[i];
            }
        }
        int sum69 = nums[6] + nums[9];
        if(max < nums[6] || max < nums[9]){
            if(sum69 % 2 == 1) sum69++;
            if(max < sum69 / 2) max = sum69/2;
        }
        System.out.println(max);

    }
}
