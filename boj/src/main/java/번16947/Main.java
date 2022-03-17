package 번16947;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static ArrayList<Integer>[] map;
    static int N;
    static boolean isCycle;
    static int[] dist;
    static boolean[] isVisited;
    static Queue<Integer> q = new LinkedList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        dist = new int[N+1];
        isVisited = new boolean[N+1];

        Arrays.fill(dist, -1);
        Arrays.fill(isVisited, false);
        map = new ArrayList[N+1];
        for(int i = 0 ; i <= N ; i++){
            map[i] = new ArrayList<>();
        }
        for(int i = 0 ; i < N ; i++){
            st = new StringTokenizer(br.readLine());
            int n1 = Integer.parseInt(st.nextToken()); int n2 = Integer.parseInt(st.nextToken());
            map[n1].add(n2);
            map[n2].add(n1);
        }
        dfs(1,0);
        bfs();
        for(int i = 1; i <= N ; i++){
            System.out.print(dist[i] + " ");
        }
        System.out.println();
    }

    private static void bfs(){
        while(!q.isEmpty()){
            int cur = q.poll();
            for (Integer next : map[cur]) {
                if(dist[next] != -1) continue;
                dist[next] = dist[cur] + 1;
                q.add(next);
            }
        }
    }

    private static void dfs(int cur, int prev) {
        isVisited[cur] = true;
        for (Integer next : map[cur]) {
            if(isVisited[next] && next != prev){ // 사이클이 생긴 경우
                isCycle = true;
                dist[next] = 0;
                q.add(next);
                break;
            } else if (!isVisited[next]){
                dfs(next,cur);
                if(isCycle){ //사이클이 있는 경우는
                    if(dist[next] == 0){
                        isCycle = false;
                    } else {
                        dist[next] = 0;
                        q.add(next);
                    }
                    return;
                }
            }

        }

    }
}
