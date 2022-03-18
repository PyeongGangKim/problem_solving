package 번16926;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N,M,R;
    static int nMax, nMin, mMax, mMin;
    static int[][] map;
    static int[][] temp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        map = new int[N][M];
        temp = new int[N][M];

        for(int i = 0 ; i < N ; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j < M ; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                temp[i][j] = map[i][j];
            }
        }

        while(R-- != 0) {
            nMin = 0; nMax = N-1; mMax = M-1 ; mMin = 0;
            while(mMin < mMax && nMin < nMax) {
                move();
                mMin++; mMax--; nMin++; nMax--;
            }
            save();
        }
        print();
    }

    private static void print() {
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }
    }

    private static void save() {
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                map[i][j] = temp[i][j];

            }
        }
    }

    private static void move() {
        //맨 위에 줄
        for(int i = mMax ; i > mMin ; i--){
            temp[nMin][i-1] = map[nMin][i];
        }
        //맨 왼쪽 줄
        for(int i = nMin ; i < nMax ; i++){
            temp[i+1][mMin] = map[i][mMin];
        }
        //맨 아래쪽 줄
        for(int i = mMin ; i < mMax ; i++){
            temp[nMax][i+1] = map[nMax][i];
        }
        //맨 오른쪽 줄
        for(int i = nMax ; i > nMin ; i--){
            temp[i-1][mMax] = map[i][mMax];
        }
    }
}
