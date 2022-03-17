package 번15988;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        int div = 1000000009;
        long[] dp = new long[1000001];
        dp[0] = 0L; dp[1] = 1L; dp[2] = 2L; dp[3] = 4L;
        for(int i = 4 ; i <= 1000000 ; i++){
            dp[i] = ((dp[i-1] + dp[i-2]) % div + dp[i-3]) % div;
        }
        for(int i = 0 ; i < T ; i++){
            System.out.println(dp[Integer.parseInt(br.readLine())]);
        }
    }
}
