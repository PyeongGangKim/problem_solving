package 숨바꼭질6;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
/*
* N명이 숨바꼭질
* 수빈이는 S점에 있음
* D만큼 움직일수 있음
* 최댓값 D를 구하시오.
* */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] nums = Arrays.stream(br.readLine().split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();
        int N = nums[0]; int X = nums[1];
        int[] brothers = Arrays.stream(br.readLine().split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();

        int[] diff = new int[N];
        for (int i = 0 ; i < N ; i++) {
            diff[i] = Math.abs(brothers[i] - X);
        }
        int res = diff[0];
        for(int i = 1 ; i < N ; i++){
            res = gcd(res, diff[i]);
        }
        System.out.println(res);
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
