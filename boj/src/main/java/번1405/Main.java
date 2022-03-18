package 번1405;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] mX = {0,0,1,-1}; // 동서남북
    static int[] mY = {1,-1,0,0};
    static double ans = 0;
    static double[] dP;
    static boolean[][] isVisited;
    static int N;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        dP = new double[4];
        for(int i = 0 ; i < 4 ; i++) {
            dP[i] = (double) Integer.parseInt(st.nextToken()) / 100;
        }
        isVisited = new boolean[31][31];
        isVisited[15][15] = true;
        dfs(15, 15, 0, 1);
        System.out.println(ans);
    }

    private static void dfs(int x, int y, int cnt, double percent) {
        if(cnt == N) {
            ans += percent;
        } else {
            for(int i = 0 ; i < 4 ; i++) {
                int nX = x + mX[i] ; int nY = y + mY[i];
                if(isVisited[nX][nY]) continue;
                isVisited[nX][nY] = true;
                dfs(nX , nY , cnt + 1, percent * dP[i]);
                isVisited[nX][nY] = false;
            }
        }
    }
}
