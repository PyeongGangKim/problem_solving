package sk;

import java.util.ArrayList;

public class 번3 {
    static class Solution {
        static int[][][] cache;
        static int div = 10000019;
        static ArrayList<Node>[][] map;
        static int R;
        static int C;
        static int[] mR = {1,0};
        static int[] mC = {0,1};
        static class Node{
            int r,c;
            public Node(int r, int c){
                this.r = r;
                this.c = c;
            }
        }
        static public int solution(int width, int height, int[][] diagonals) {
            R = height;
            C = width;
            cache = new int[height+1][width+1][2];
            map = new ArrayList[R+1][C+1];
            for(int i = 0 ; i <= R ; i++){
                for(int j = 0 ; j <= C ; j++){
                    map[i][j] = new ArrayList<>();
                }
            }
            for(int i = 0 ; i < diagonals.length ; i++){
                map[diagonals[i][0] - 1][diagonals[i][1]].add(new Node(diagonals[i][0], diagonals[i][1] - 1));
                map[diagonals[i][0]][diagonals[i][1] - 1].add(new Node(diagonals[i][0] - 1, diagonals[i][1]));
            }
            for(int i = 0 ; i <= R ; i++){
                for(int j = 0 ; j <= C ; j++){
                    cache[i][j][0] = -1;
                    cache[i][j][1] = -1;
                }
            }
            int num;
            System.out.println(dp(0,0,0));
            return num = 0;
        }
        static public int dp(int r, int c, int isUseDiagonals){
            if(r == R && c == C){
                if(isUseDiagonals == 1) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
            if(cache[r][c][isUseDiagonals] != -1) return cache[r][c][isUseDiagonals] % div;
            cache[r][c][isUseDiagonals] = 0;
            for(int i = 0 ; i < 2 ; i++){
                int nR = mR[i] + r; int nC = mC[i] + c;
                if(nR < 0 || nR > R || nC < 0 || nC > C) continue;
                cache[r][c][isUseDiagonals] = ((dp(nR, nC, isUseDiagonals) % div) + cache[r][c][isUseDiagonals]) % div ;
            }

            if(isUseDiagonals == 0 && map[r][c].size() != 0){
                for(int i = 0 ; i < map[r][c].size() ; i++){
                    int nR = map[r][c].get(i).r ; int nC = map[r][c].get(i).c;
                    cache[r][c][isUseDiagonals] = ((dp(nR, nC, 1) % div) + cache[r][c][isUseDiagonals]) % div;
                }
            }

            return cache[r][c][isUseDiagonals] % div;
        }
    }

    public static void main(String[] args) {
        Solution.solution(51,37, new int[][]{new int[] {17,19}});
    }
}
