package 번1976;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N,M;
    static boolean[][] map;
    static int[] parent;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        map = new boolean[N][N];
        parent = new int[N];
        for(int i = 0 ; i < N ; i++) {
            parent[i] = i;
        }
        for(int i = 0 ; i < N ; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j < N ; j++){
                if(st.nextToken().equals("1")){
                    union(i,j);
                }

            }
        }
        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken()) - 1;
        boolean isPossible = true;
        for(int i = 0 ; i < M - 1 ; i++) {
            int cur = Integer.parseInt(st.nextToken()) - 1;
            if(find(start) != find(cur)) {
                isPossible = false;
            }

            start = cur;
        }

        if(isPossible)
            System.out.println("YES");
        else
            System.out.println("NO");

    }

    private static void union(int i, int j) {
        i = find(i);
        j = find(j);
        if(i != j) {
            if(i < j) parent[j] = i;
            else parent[i] = j;
        }
    }

    private static int find(int i) {
        if(i == parent[i]) return i;
        else return parent[i] = find(parent[i]);
    }
}
