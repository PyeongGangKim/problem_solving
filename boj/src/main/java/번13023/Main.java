package 번13023;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static HashMap<Integer, ArrayList<Integer>> graph = new HashMap<>();
    static boolean[] isVisited;
    static boolean ans;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for(int i = 0 ; i < M ; i++){
            st = new StringTokenizer(br.readLine());
            int node1 = Integer.parseInt(st.nextToken()); int node2 = Integer.parseInt(st.nextToken());
            if(graph.get(node1) == null){
                ArrayList<Integer> tmp = new ArrayList<>();
                tmp.add(node2);
                graph.put(node1,tmp);
            } else {
                graph.get(node1).add(node2);
            }
            if(graph.get(node2) == null){
                ArrayList<Integer> tmp = new ArrayList<>();
                tmp.add(node1);
                graph.put(node2,tmp);
            } else {
                graph.get(node2).add(node1);
            }
        }
        ans = false;
        isVisited = new boolean[N];
        for(int i = 0 ; i < N ; i++){
            if(ans) break;
            Arrays.fill(isVisited, false);
            isVisited[i] = true;
            dfs(i,1);
        }

        System.out.println((ans) ? 1 : 0);
    }

    private static void dfs(int cur, int depth) {
        ArrayList<Integer> tmp = graph.get(cur);
        if(tmp == null) return;
        if(depth >= 5){
            ans = true;
            return;
        }
        for(int i = 0 ; i < tmp.size() ; i++){
            int next = tmp.get(i);
            if(isVisited[next]) continue;
            isVisited[next] = true;
            dfs(next, depth + 1);
            isVisited[next] = false;
        }
    }

}
