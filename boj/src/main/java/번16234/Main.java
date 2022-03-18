package 번16234;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static class Node{
        int x,y;
        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static class Country{
        int cnt;
        int sum;
        int num;

        public Country(int cnt, int sum, int num) {
            this.cnt = cnt;
            this.sum = sum;
            this.num = num;
        }
    }
    static int N,L,R;
    static int[][] map;
    static int[][] tmp;
    static int[] mX = {0,0,1,-1};
    static int[] mY = {1,-1,0,0};
    static Queue<Country> moveCountry = new LinkedList<Country>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        map = new int[N][N];
        tmp = new int[N][N];
        for(int i = 0 ; i < N ; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j < N ; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int ans = 0;
        while(true) {
            int cnt = 1;

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (tmp[i][j] == 0) {
                        bfs(cnt, i, j);
                        cnt++;
                    }
                }
            }
            if(cnt == N*N + 1) break;
            move();
            ans++;
        }

        System.out.println(ans);
    }

    private static void move() {
        while(!moveCountry.isEmpty()) {
            Country cur = moveCountry.poll();
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if(tmp[i][j] == cur.num) {
                        map[i][j] = cur.sum / cur.cnt;
                        tmp[i][j] = 0;
                    }
                }
            }
        }
    }

    private static void bfs(int num, int i, int j) {
        Queue<Node> q = new LinkedList<>();
        tmp[i][j] = num;
        int sum = 0;
        int cnt = 0;
        q.add(new Node(i,j));
        while(!q.isEmpty()){
            Node cur = q.poll();
            sum += map[cur.x][cur.y];
            cnt++;
            for(int k = 0 ; k < 4 ; k++){
                int nX = cur.x + mX[k] ; int nY = cur.y + mY[k];
                if(nX < 0 || nX >= N || nY < 0 || nY >= N) continue;
                if(tmp[nX][nY] != 0) continue;
                int diff = Math.abs(map[cur.x][cur.y] - map[nX][nY]);
                if( diff >= L && diff <= R){
                    tmp[nX][nY] = num;
                    q.add(new Node(nX,nY));
                }

            }
        }
        moveCountry.add(new Country(cnt,sum,num));
    }
}
