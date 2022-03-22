package 번13460;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static int[][] map;

    static class Node {
        Ball blueBall; // blue ball 좌표
        Ball redBall;// red ball 좌표
        int cnt; // 몇 번째 인지

        public Node(Ball redBall, Ball blueBall, int cnt) {
            this.blueBall = blueBall;
            this.redBall = redBall;
            this.cnt = cnt;
        }

    }

    static class Ball {
        int n, m;

        public Ball(int n, int m) {
            this.n = n;
            this.m = m;
        }
    }
    static Ball blueBallStart;
    static Ball redBallStart;
    static boolean[][][][] isVisited; // max value 10*10*10*10
    static int[] mN = {0,0,1,-1}; //  오른쪽으로 기울이기, 왼쪽, 아래쪽, 위쪽
    static int[] mM = {1,-1,0,0};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N][M];
        isVisited = new boolean[N][M][N][M];
        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            for (int j = 0; j < M; j++) {
                if (tmp.charAt(j) == '#')
                    map[i][j] = -1;
                else if (tmp.charAt(j) == '.')
                    map[i][j] = 0;
                else if (tmp.charAt(j) == 'O')
                    map[i][j] = 1;
                else if (tmp.charAt(j) == 'R') {
                    map[i][j] = 0;
                    redBallStart = new Ball(i,j);
                } else {
                    map[i][j] = 0;
                    blueBallStart = new Ball(i,j);
                }
            }
        }
        System.out.println(bfs());
    }

    private static int bfs() {
        Queue<Node> q = new LinkedList<>();
        isVisited[redBallStart.n][redBallStart.m][blueBallStart.n][blueBallStart.m] = true;
        q.add(new Node(redBallStart, blueBallStart, 0));
        while(!q.isEmpty()){
            Node cur = q.poll();
            if(cur.cnt >= 10) break;
            for(int i = 0 ; i < 4 ; i++){ //오 왼 아 위
                boolean redExit = false;
                boolean blueExit = false;
                Ball nextRedBall = new Ball(cur.redBall.n, cur.redBall.m);
                Ball nextBlueBall = new Ball(cur.blueBall.n, cur.blueBall.m);
                //빨간 볼 부터
                while(map[nextRedBall.n + mN[i]][nextRedBall.m +mM[i]] != -1){
                    nextRedBall.n += mN[i]; nextRedBall.m += mM[i];
                    if(map[nextRedBall.n][nextRedBall.m] == 1) {
                        redExit = true;
                        break;
                    }
                }
                //파란 볼
                while(map[nextBlueBall.n + mN[i]][nextBlueBall.m + mM[i]] != -1){
                    nextBlueBall.n += mN[i]; nextBlueBall.m += mM[i];
                    if(map[nextBlueBall.n][nextBlueBall.m] == 1) {
                        blueExit = true;
                        break;
                    }
                }

                if(blueExit) continue; // 둘다 일 경우는 그냥 넘기기
                else if (redExit && !blueExit) return cur.cnt + 1;

                //겹치는 경우 처리
                if(nextBlueBall.n == nextRedBall.n && nextBlueBall.m == nextRedBall.m) {
                    if(i == 0){ // 오른쪽으로 기울이는 경우
                        if(cur.redBall.m < cur.blueBall.m){
                            nextRedBall.m--;
                        } else nextBlueBall.m--;
                    } else if(i == 1) { // 왼쪽으로 기울이는 경우
                        if(cur.redBall.m < cur.blueBall.m){
                            nextBlueBall.m++;
                        } else nextRedBall.m++;
                    } else if(i == 2) { // 아래쪽으로 기울이는 경우
                        if(cur.redBall.n < cur.blueBall.n){
                            nextRedBall.n--;
                        } else nextBlueBall.n--;
                    } else { // 위쪽으로 기울이는 경우
                        if(cur.redBall.n < cur.blueBall.n) {
                            nextBlueBall.n++;
                        } else nextRedBall.n++;
                    }
                }
                if(!isVisited[nextRedBall.n][nextRedBall.m][nextBlueBall.n][nextBlueBall.m]){
                    isVisited[nextRedBall.n][nextRedBall.m][nextBlueBall.n][nextBlueBall.m] = true;
                    q.add(new Node(nextRedBall, nextBlueBall, cur.cnt+1));
                }

            }
        }
        return -1;
    }
}
