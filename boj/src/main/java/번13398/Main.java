package 번13398;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int[] nums = Arrays.stream(br.readLine().split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();

        int[][] dp = new int[nums.length][2];

        dp[0][0] = nums[0]; // 값을 제거하지 않은 경우
        dp[0][1] = 0; // 값을 제거한 경우
        int res = dp[0][0];
        for(int i = 1 ; i < nums.length ; i++){
            dp[i][0] = Math.max(dp[i-1][0] + nums[i] , nums[i]); //현재꺼와 값을 제거하지 않은 이전 값에 현재 꺼를 더한 것중 더 큰 것을 정하기
            dp[i][1] = Math.max(dp[i-1][1] + nums[i], dp[i-1][0]);// 이미 제거한 값들에 현재 꺼 더한 것과 제거하지 않은 값에 현재 값을 제거한 거 비교
            res = Math.max(res, Math.max(dp[i][0], dp[i][1]));
        }
        System.out.println(res);
    }
}
