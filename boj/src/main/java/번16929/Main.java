package 번16929;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int M;
    static boolean[] doHaveAlpha;
    static boolean[][] isVisited;
    static int[][] map;
    static int[] mX = {0,-1,0,1};
    static int[] mY = {1,0,-1,0};
    static class Node{
        int dir;
        int n;
        int m;

        public Node(int dir, int n, int m) {
            this.dir = dir;
            this.n = n;
            this.m = m;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        doHaveAlpha = new boolean[27];
        map = new int[N][M];
        Arrays.fill(doHaveAlpha, false);
        for(int i = 0 ; i < N ; i++){
            String tmp = br.readLine();
            for(int j = 0 ; j < M ; j++){
                doHaveAlpha[tmp.charAt(j) - 'A'] = true;
                map[i][j] = tmp.charAt(j) - 'A';
            }
        }
        boolean isCycle = false;
        isVisited = new boolean[N][M];
        for(int i = 0 ; i < 26 ; i++){
            if(!doHaveAlpha[i]) continue;
            for (int z = 0 ; z < N ; z++){
                Arrays.fill(isVisited[z], false);
            }
            for(int j = 0 ; j < N ; j++){
                for(int k = 0 ; k < M ; k++){
                    if(map[j][k] == i && !isVisited[j][k]){
                        isCycle = bfs(i,j,k);
                        if(isCycle){
                            System.out.println("Yes");
                            return;
                        }
                    }
                }
            }
        }
        System.out.println("No");
    }

    private static boolean bfs(int alpha, int n, int m) {
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(-100,n,m));
        isVisited[n][m] = true;
        while(!q.isEmpty()){
            Node cur = q.poll();
            int prevDir = (cur.dir + 2) % 4;
            for(int i = 0 ; i < 4 ; i++){
                if(i == prevDir) continue;
                int nN = cur.n + mX[i] ; int nM = cur.m + mY[i];
                if(nN < 0 || nN >= N || nM < 0 || nM >= M) continue;
                if(alpha != map[nN][nM]) continue;
                if(isVisited[nN][nM]) return true;
                isVisited[nN][nM] = true;
                q.add(new Node(i,nN,nM));
            }
        }
        return false;
    }
}
