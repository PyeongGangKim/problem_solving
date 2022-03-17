package 번4963;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int[][] map;
    static boolean[][] isVisited;
    static int w,h;
    static int[] mX = {0,0,1,-1,1,-1,1,-1};
    static int[] mY = {1,-1,0,0,1,-1,-1,1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        while(true){
            st = new StringTokenizer(br.readLine());
            w = Integer.parseInt(st.nextToken()); h = Integer.parseInt(st.nextToken());
            map = new int[h][w];
            isVisited = new boolean[h][w];
            if(w == 0 && h == 0) break;
            for(int i = 0 ; i < h ; i++){
                st = new StringTokenizer(br.readLine());
                for(int j = 0 ; j < w ; j++){
                    map[i][j] = Integer.parseInt(st.nextToken());
                    isVisited[i][j] = false;
                }
            }


            int ans = 0;
            for(int i = 0 ; i < h ; i++){
                for(int j = 0 ; j < w ; j++){
                    if(map[i][j] == 1 && !isVisited[i][j]){
                        ans++;
                        dfs(i,j);
                    }
                }
            }
            System.out.println(ans);
        }
    }

    private static void dfs(int x, int y) {
        for(int i = 0 ; i < 8 ; i++){
            int nX = mX[i] + x ; int nY = mY[i] + y;
            if(nX < 0 || nX >= h || nY < 0 || nY >= w) continue;
            if(map[nX][nY] == 0 || isVisited[nX][nY]) continue;
            isVisited[nX][nY] = true;
            dfs(nX,nY);
        }
    }
}
