package 번10974;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Stack;

public class Main {
    static int N;
    static boolean[] check;
    static Stack<Integer> nums = new Stack<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        check = new boolean[N+1];
        Arrays.fill(check, false);
        dfs();
    }

    private static void dfs() {
        if(nums.size() == N){
            Iterator<Integer> iterator = nums.iterator();
            for (Iterator<Integer> it = iterator; it.hasNext(); ) {
                Integer n = it.next();
                System.out.print(n + " ");
            }
            System.out.println();
        } else {
            for(int i = 1 ; i <= N ; i++){
                if(check[i]) continue;
                nums.push(i);
                check[i] = true;
                dfs();
                check[i] = false;
                nums.pop();
            }
        }
    }
}
