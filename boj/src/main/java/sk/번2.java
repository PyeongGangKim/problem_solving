package sk;

public class 번2 {
    /*
2,3,4는 따로 처리
홀: N-2, N-3, N-5, (N-5 == 2) ? 1 : N - 6 ,...,1
짝: N-2, N-3, N-5 , (N-5 == 3) ? 1 : N - 6 ,...,1

시계방향시 (0,0)부터 출발은
mR[0][] = {0,1,0,-1};
mC[0][] = {1,0,-1,0};
반시계방향
mR[0][] = {1,0,-1,0};
mC[0][] = {0,1,0,-1};
*/

    static class Solution {
        static public int[][] solution(int n, boolean clockwise) {
            int[] mR = {0,1,0,-1};
            int[] mC = {1,0,-1,0};
            int[] rMR = {1,0,-1,0};
            int[] rMC = {0,1,0,-1};
            int[] sR = {0,0,n-1,n-1};
            int[] sC = {0,n-1,n-1,0};
            int[] rSR = {0,n-1,n-1,0};
            int[] rSC = {0,0,n-1,n-1};
            int[][] answer = new int[n][n];
            if(n==1){
                answer[0][0] = 1;
            }
            else if(n == 2){
                for(int i = 0 ; i < n ; i++){
                    for( int j = 0 ; j < n ; j++){
                        answer[i][i] = 1;
                    }
                }
            } else {
                if(n % 2 == 0) {
                    if(clockwise){
                        for(int i = 0 ; i < 4 ; i++){
                            //n-2부터 더하기
                            int r = sR[i]; int c = sC[i];
                            int plus = n-1;
                            int idx = i;
                            int num = 1;
                            while(plus > 0){
                                for(int k = 0 ; k < plus ; k++){
                                    answer[r][c] = num++;
                                    if(k != plus-1 ) {
                                        r += mR[idx];
                                        c += mC[idx];
                                    }
                                }
                                plus -= 2;

                                idx = (idx + 1) % 4;
                                r += mR[idx]; c += mC[idx];

                            }
                        }
                    } else {
                        for(int i = 0 ; i < 4 ; i++){
                            //n-2부터 더하기
                            int r = rSR[i]; int c = rSC[i];
                            int plus = n-1;
                            int idx = i;
                            int num = 1;
                            while(plus > 0){
                                for(int k = 0 ; k < plus ; k++){
                                    answer[r][c] = num++;
                                    if(k != plus-1) {
                                        r += rMR[idx];
                                        c += rMC[idx];
                                    }
                                }
                                plus -= 2;
                                idx = (idx + 1) % 4;
                                r += rMR[idx]; c += rMC[idx];
                            }
                        }
                    }
                } else { // 홀수
                    if(clockwise){
                        for(int i = 0 ; i < 4 ; i++){
                            //n-2부터 더하기
                            int r = sR[i]; int c = sC[i];
                            int plus = n-1;
                            int idx = i;
                            int num = 1;
                            while(plus > 0){
                                for(int k = 0 ; k < plus ; k++){
                                    answer[r][c] = num++;
                                    if(k != plus-1){
                                        r += mR[idx];
                                        c += mC[idx];
                                    }
                                }
                                if(plus != 2) plus -= 2;
                                else plus = 1;
                                idx = (idx + 1) % 4;
                                r += mR[idx]; c += mC[idx];
                            }
                        }
                    } else {
                        for(int i = 0 ; i < 4 ; i++){
                            //n-2부터 더하기
                            int r = rSR[i]; int c = rSC[i];
                            int plus = n-1;
                            int idx = i;
                            int num = 1;
                            while(plus > 0){
                                for(int k = 0 ; k < plus ; k++){
                                    answer[r][c] = num++;
                                    if(k != plus-1) {
                                        r += rMR[idx];
                                        c += rMC[idx];
                                    }
                                }
                                if(plus != 2) plus -= 2;
                                else plus = 1;
                                idx = (idx + 1) % 4;
                                r += rMR[idx]; c += rMC[idx];
                            }
                        }
                    }

                }
            }
            for (int[] ints : answer) {
                for (int anInt : ints) {
                    System.out.print(anInt + " ");
                }
                System.out.println();
            }
            return answer;
        }
    }
    public static void main(String[] args) {
        Solution.solution(6,false);
    }
}
