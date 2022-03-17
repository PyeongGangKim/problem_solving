package 번1261;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N,M;
    static int[][] map;
    static int[][] isVisited;
    static int ans = Integer.MAX_VALUE;
    static int[] mX = {0,0,1,-1};
    static int[] mY = {-1,1,0,0};
    static class Node implements Comparable<Node>{
        int x,y;
        int cnt;

        public Node(int x, int y, int cnt) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }

        @Override
        public int compareTo(Node o) {
            return cnt - o.cnt;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[M][N];
        isVisited = new int[M][N];
        for(int i = 0 ; i < M ; i++){
            Arrays.fill(isVisited[i], -1);
        }

        for(int i = 0 ; i < M ; i++){
            st = new StringTokenizer(br.readLine());
            String tmp = st.nextToken();
            for(int j = 0 ; j < N ; j++){
                map[i][j] = tmp.charAt(j) - '0';
            }
        }

        bfs();
        System.out.println(ans);

    }

    private static void bfs() {
        PriorityQueue<Node> q = new PriorityQueue<>();
        q.add(new Node(0,0,0));
        isVisited[0][0] = 0;
        while(!q.isEmpty()){
            Node node = q.poll();
            int x = node.x; int y = node.y; int cnt = node.cnt;

            if(x == M - 1 && y == N - 1){
                ans = cnt;
                return;
            }
            for(int i = 0 ; i < 4 ; i++){
                int nX = mX[i] + x ; int nY = mY[i] + y;

                if(nX < 0 || nX >= M || nY < 0 || nY >= N) continue;
                if(isVisited[nX][nY] != -1) continue;

                if(map[nX][nY] == 1){ // 벽을 뚫는 경우
                    q.add(new Node(nX,nY, cnt + 1));
                    isVisited[nX][nY] = cnt + 1;
                }  else { // 벽을 뚫지 않는 경우
                    q.add(new Node(nX, nY, cnt));
                    isVisited[nX][nY] = cnt;
                }
            }
        }
    }
}
