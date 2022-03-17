package 번1913;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int[][] res;
    static int[] mR = {0,-1,0,1};
    static int[] mC = {1,0,-1,0};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int target = Integer.parseInt(st.nextToken());
        res = new int[N+1][N+1];
        int num = N*N;
        int resC = 0; int resR = 0;
        for(int i = 1 ; i <= N ; i++){
            if(num == target) {
                resR = i;
                resC = 1;
            }
            res[i][1] = num--;
        }

        int row = N; int col = 1;
        int cur = N - 1;
        int dir = 0;
        int cnt = 0;
        while(num >= 1){
            cnt++;
            for(int i = cur ; i > 0 ; i--){
                int nRow = row + mR[dir] ; int nCol = col + mC[dir];
                if(num == target){
                    resR = nRow;
                    resC = nCol;
                }

                res[nRow][nCol] = num--;
                row = nRow; col = nCol;
            }
            dir = (dir + 1) % 4;
            if(cnt == 2){
                cnt = 0;
                cur--;
            }
        }
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= N ; j++){
                System.out.print(res[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println(resR + " " + resC);
    }
}
