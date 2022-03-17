package GCD합;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for(int i = 0 ; i < t ; i++){
            long res = 0L;
            int[] nums = Arrays.stream(br.readLine().split(" ")).mapToInt( n-> Integer.parseInt(n)).toArray();
            for(int j = 1 ; j <= nums[0] ; j++){
                for(int k = j+1 ; k <= nums[0] ; k++){
                    res += gcd(nums[j], nums[k]);
                }
            }
            System.out.println(res);
        }
    }

    static int gcd(int a, int b){
        int tmp, n;
        if(a<b){
            tmp = a;
            a = b;
            b = tmp;
        }

        while(b!=0){
            n = a%b;
            a = b;
            b = n;
        }
        return a;

    }
}
