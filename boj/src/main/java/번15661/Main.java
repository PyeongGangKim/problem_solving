package 번15661;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;

public class Main {
    static int N;
    static int[][] values;
    static boolean[] isPicked;
    static int ans = Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        values = new int[N][N];
        isPicked = new boolean[N];
        for(int i = 0 ; i < N ; i++){
            values[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(n -> Integer.parseInt(n)).toArray();
        }

        for(int i = 1 ; i <= N / 2 ; i++){
            Arrays.fill(isPicked, false);
            dfs(i,0,0);
        }

        System.out.println(ans);
    }

    static void dfs(int maxPick,int idx, int picked){
        if(maxPick == picked){
            calValuesDiff();
        } else {
            for(int i = idx ; i < N ; i++){
                if(isPicked[i]) continue;
                isPicked[i] = true;
                dfs(maxPick, i+1, picked + 1);
                isPicked[i] = false;
            }
        }
    }

    private static void calValuesDiff() {
        ArrayList<Integer> picked = new ArrayList<>();
        ArrayList<Integer> unpicked = new ArrayList<>();
        for(int i = 0 ; i < N ; i++){
            if(isPicked[i]) picked.add(i);
            else unpicked.add(i);
        }
        int pickedValues = calValues(picked);
        int unpickedValues = calValues(unpicked);
        ans = Math.min(ans, Math.abs(pickedValues - unpickedValues));
    }

    private static int calValues(ArrayList<Integer> indexs) {
        int v = 0;
        for (Integer i : indexs) {
            for (Integer j : indexs) {
                v += values[i][j];
            }
        }
        return v;
    }
}
