package 카드구매하기2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static int[] cache = new int[1001];
    static int maxNum = 1000000001;

    public static void main(String[] args) throws IOException {
        /*
        * 등급을 나누는 색 8가지 존재
        * 각 카드를 가지고 있는 카드팩이 존재.
        * 카드팩의 종류
        * - 카드 1개가 포함된 카드팩
        * - 카드 2개가 포함된 카드팩
        * - ... 카드 N개가 포함된 카드팩
        * 총 N가지 존재.
        * 최소로 돈을 사용해서 카드 N개 구매. 카드가 i개 포함된 카드팩의 가격은 Pi원.
        * 카드 갯수를 정확히 맞춰야됨.
        * 최대 개수에서 내려가면서 계산
        * */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] values = Arrays.stream(br.readLine().split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();
        Arrays.fill(cache, -1);
        System.out.println(dp(N,values));

    }

    static int dp(int n, int[] values){
        if(n == 0) return 0;
        Integer res = cache[n];
        if(res != -1) return res;
        res = maxNum;
        for(int i = n ; i >= 1 ; i--){
            res = Math.min(res, dp(n-i,values) + values[i - 1]);
        }

        cache[n] = res;
        return res;
    }
}
