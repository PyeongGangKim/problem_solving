package 번20058;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int[][] A;
    static int[][] temp; // rotate할 때, 얼음 줄일때 저장할 배열
    static int[] mR = {0,0,1,-1};
    static int[] mC = {1,-1,0,0};
    static int Q;
    static int N;
    static boolean[][] isVisited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = (int) Math.pow(2,Integer.parseInt(st.nextToken()));
        Q = Integer.parseInt(st.nextToken());
        A = new int[N][N];
        temp = new int[N][N];
        for (int i = 0 ; i < N ; i++){
            st = new StringTokenizer(br.readLine());
            for (int j = 0 ; j < N ; j++){
                A[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        st = new StringTokenizer(br.readLine());
        while(Q-- != 0){
            int L = (int) Math.pow(2,Integer.parseInt(st.nextToken()));
            for(int i = 0 ; i < N ; i += L){
                for(int j = 0 ; j < N ; j += L){
                    rotate(i,j,L);
                }
            }
            save();
            melt();
            save();
        }
        System.out.println(iceSum());
        int part = 0;
        isVisited = new boolean[N][N];
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(!isVisited[i][j] && A[i][j] != 0){
                    part = Math.max(part,bfs(i,j));
                }
            }
        }
        System.out.println(part);
    }
    static class Node{
        int r,c;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
    private static int bfs(int r, int c) {
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(r,c));
        isVisited[r][c] = true;
        int cnt = 0;
        while(!q.isEmpty()){
            Node n = q.poll();
            cnt++;
            for(int i = 0 ; i < 4 ; i++){
                int nR = n.r + mR[i]; int nC = n.c + mC[i];
                if(nR < 0 || nR >= N || nC < 0 || nC >= N) continue;
                if(A[nR][nC] == 0 || isVisited[nR][nC]) continue;
                isVisited[nR][nC] = true;
                q.add(new Node(nR,nC));
            }
        }

        return cnt;
    }

    private static long iceSum() {
        long sum = 0L;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                sum += A[i][j];
            }
        }
        return sum;
    }

    private static void melt() {
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                int cnt = 0;
                if(A[i][j] == 0) continue;
                for(int k = 0 ; k < 4 ; k++){
                    int nR = i + mR[k]; int nC = j + mC[k];

                    if(nR < 0 || nC < 0 || nR >= N || nC >= N) continue;
                    if(A[nR][nC] == 0) continue;
                    cnt++;
                }
                if(cnt <= 2){
                    temp[i][j] = A[i][j] - 1;
                }
            }
        }
    }

    private static void save() {
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                A[i][j] = temp[i][j];
            }
        }
    }

    private static void rotate(int r, int c, int L) {
        for(int i = 0 ; i < L ; i++){
            for(int j = 0 ; j < L ; j++){
                temp[r+j][c + L - i - 1] = A[r+i][c+j];
            }
        }
    }

}
