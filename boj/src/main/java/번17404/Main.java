package 번17404;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int N;
    static int[][] cache, cost;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        cost = new int[N][3];
        cache = new int[N][3];
        for(int i = 0 ; i < N ; i++){
            cost[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(n -> Integer.parseInt(n)).toArray();
        }

        int ans = Integer.MAX_VALUE;
        ans = Math.min(ans, dp(0));
        ans = Math.min(ans, dp(1));
        ans = Math.min(ans, dp(2));

        System.out.println(ans);
    }
    static int dp(int s){
        cache[0][0] = cost[0][0];
        cache[0][1] = cost[0][1];
        cache[0][2] = cost[0][2];

        int notS1 = (s+1) % 3;
        int notS2 = (s+2) % 3;

        //다음꺼는 s를 선택하면 안됨
        cache[1][s] = Integer.MAX_VALUE;
        cache[1][notS1] = cache[0][s] + cost[1][notS1];
        cache[1][notS2] = cache[0][s] + cost[1][notS2];

        for(int i = 2 ; i < N ; i++){
            cache[i][0] = Math.min(cache[i-1][1], cache[i-1][2]) + cost[i][0];
            cache[i][1] = Math.min(cache[i-1][0], cache[i-1][2]) + cost[i][1];
            cache[i][2] = Math.min(cache[i-1][0], cache[i-1][1]) + cost[i][2];

        }

        return Math.min(cache[N-1][notS1], cache[N-1][notS2]);
    }

}
