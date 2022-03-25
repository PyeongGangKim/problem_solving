package 번18430;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, M, K;
    static int[][] map;
    static int[][] mX = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    static int[][] mY = {{1, 0}, {1, 0}, {0, 1}, {0, 1}};
    static int res = 0;
    static boolean[][] isVisited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N][M];
        isVisited = new boolean[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dfs(0, 0, 0);
        System.out.println(res);
    }

    private static void dfs(int x, int y, int sum) {
        System.out.println(x + " " + y + " " + sum);
        res = Math.max(res, sum);
        isVisited[x][y] = true;
        for(int i = 0 ; i < N ; i++) {
            for(int j = y ; j < M ; j++) {
                for (int k = 0; k < 4; k++) {
                    int nX1 = i + mX[k][0];
                    int nY1 = j + mY[k][0];
                    int nX2 = i + mX[k][1];
                    int nY2 = j + mY[k][1];
                    if (nX1 < 0 || nX1 >= N || nY1 < 0 || nY1 >= M || nX2 < 0 || nX2 >= N || nY2 < 0 || nY2 >= M)
                        continue;
                    if (isVisited[nX1][nY1] || isVisited[nX2][nY2])
                        continue;
                    isVisited[nX1][nY1] = true;
                    isVisited[nX2][nY2] = true;
                    for (int e = i; e < N; e++) {
                        for (int f = j; f < M; f++) {
                            if (isVisited[e][f])
                                continue;
                            dfs(e, f, sum + map[x][y] * 2 + map[nX1][nY1] + map[nX2][nY2]);
                        }
                    }
                    isVisited[nX1][nY1] = false;
                    isVisited[nX2][nY2] = false;

                }
            }
        }
        isVisited[x][y] = false;
    }
}
