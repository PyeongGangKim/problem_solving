package 번20056;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static int[][] map;
    static ArrayList<FireBall> list;
    static int N, M, K;
    static int[] mR = {-1,-1,0,1,1,1,0,-1};
    static int[] mC = {0,1,1,1,0,-1,-1,-1};
    static class FireBall{
        int r,c,m,s,d;

        public FireBall(int r, int c, int m, int s, int d) {
            this.r = r;
            this.c = c;
            this.m = m;
            this.s = s;
            this.d = d;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        list = new ArrayList<>();
        map = new int[N][N];

        for (int i = 0 ; i < M ; i++) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken()) - 1;
            int m = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            list.add(new FireBall(r,c,m,s,d));
            map[r][c]++;
        }
        for(int i = 0 ; i < K ; i++){
            move();
            samePlaceCheck();
        }
        System.out.println(getResult());
    }

    private static int getResult() {
        int sum = 0;
        for (FireBall fireBall : list) {
            sum += fireBall.m;
        }
        return sum;
    }

    private static void samePlaceCheck() {
        for (int i = 0 ; i < N ; i++){
            for( int j = 0 ; j < N ; j++){
                if(map[i][j] > 1) {
                    if(divideFireBall(i,j)) {
                        map[i][j] = 4;
                    } else map[i][j] = 0;
                }
            }
        }
    }

    private static boolean divideFireBall(int r, int c) {
        int sumM = 0;
        int sumS = 0;
        boolean sameDir = true;
        int curDir = -1;
        int cnt = 0;
        for (int i = 0 ; i < list.size() ; i++) {
            FireBall fireBall = list.get(i);

            if(fireBall.r == r && fireBall.c == c){ // 같다면 더하기
                cnt++;
                sumM += fireBall.m; sumS += fireBall.s;
                if(sameDir){ // 지금까지 같은 경우
                    if(curDir == -1){
                        curDir = fireBall.d % 2;
                    } else {
                        if(curDir != fireBall.d % 2) sameDir = false;
                    }
                }
                list.remove(i);
                i--;
            }

        }

        int divM = sumM / 5;
        int divS = sumS / cnt;

        if(divM == 0) return false;
        if(sameDir){
            for(int i = 0 ; i < 7 ; i += 2){
                list.add(new FireBall(r,c,divM,divS,i));
            }
        } else {
            for(int i = 1 ; i < 8 ; i += 2){
                list.add(new FireBall(r,c,divM,divS,i));
            }
        }
        return true;
    }

    private static void move() {
        for (FireBall fireBall : list) {
            int nR = fireBall.r + mR[fireBall.d] * fireBall.s;
            int nC = fireBall.c + mC[fireBall.d] * fireBall.s;
            nR = boundaryCheck(nR);
            nC = boundaryCheck(nC);
            map[fireBall.r][fireBall.c]--;
            map[nR][nC]++;
            fireBall.r = nR;
            fireBall.c = nC;
        }

    }

    private static int boundaryCheck(int num) {
        if(num < 0) {
            while(num < 0) num = N + num;
        }
        else if(num >= N) {
            while(num >= N) num = num - N;
        }
        return num;
    }
}
