package 번15990;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long[][] dp = new long[100001][4];
        int div = 1000000009;

        int t = Integer.parseInt(br.readLine());
        dp[1][1] = 1L; dp[1][2] = 0L; dp[1][3] = 0L;
        dp[2][1] = 0L; dp[2][2] = 1L; dp[2][3] = 0L;
        dp[3][1] = 1L; dp[3][2] = 1L; dp[3][3] = 1L;

        for(int i = 4 ; i < 100001 ; i++){
            dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % div;
            dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % div;
            dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % div;
        }

        for(int i = 0 ; i < t ; i++){
            int n = Integer.parseInt(br.readLine());
            System.out.println((dp[n][1] + dp[n][2] + dp[n][3]) % div);
        }
    }
}
