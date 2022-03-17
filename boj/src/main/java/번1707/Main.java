package 번1707;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int K;
    static int V, E;
    static int[] color;
    static ArrayList<Integer>[] graph;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken());
        while(K-- != 0){
            st = new StringTokenizer(br.readLine());
            V = Integer.parseInt(st.nextToken()); E = Integer.parseInt(st.nextToken());
            init(V);
            for(int i = 0 ; i < E ; i++){
                st = new StringTokenizer(br.readLine());
                int n1 = Integer.parseInt(st.nextToken()); int n2 = Integer.parseInt(st.nextToken());
                graph[n1].add(n2);
                graph[n2].add(n1);
            }
            boolean isGraph = true;
            color = new int[V+1];
            Arrays.fill(color, -1);
            for(int i = 1 ; i <= V ; i++){
                if(color[i] == -1){
                    isGraph = bfs(i);
                    if(!isGraph) break;
                }

            }
            if(isGraph) System.out.println("YES");
            else System.out.println("NO");
        }



    }

    private static boolean bfs(int num) {

        color[num] = 0;
        Queue<Integer> q = new LinkedList<>();
        q.add(num);
        while(!q.isEmpty()){
            int n = q.poll();
            int curColor = color[n];
            for(int i = 0 ; i < graph[n].size() ; i++){
                int next = graph[n].get(i);
                //System.out.println(n + " " + curColor + " " + next + " " + color[next]);
                if(curColor == color[next]) return false;
                if(color[next] == -1) {
                    color[next] = Math.abs(curColor - 1);// 다르다면
                    q.add(next);
                }
            }
        }
        return true;
    }

    private static void init(int V) {
        graph = new ArrayList[V +1];
        for(int i = 0; i <= V; i++){
            graph[i] = new ArrayList<>();
        }
    }


}
