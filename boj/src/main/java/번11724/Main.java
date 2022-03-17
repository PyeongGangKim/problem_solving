package 번11724;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class Main {
    static int N, M;
    static HashMap<Integer,ArrayList<Integer>> graph = new HashMap<>();
    static boolean[] isVisited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] nums = Arrays.stream(br.readLine().split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();
        N = nums[0]; M = nums[1];

        isVisited = new boolean[N+1];
        Arrays.fill(isVisited, false);

        for(int i = 0 ; i < M ; i++){
            int[] nodes = Arrays.stream(br.readLine().split(" ")).mapToInt(n -> Integer.parseInt(n)).toArray();
            if(graph.get(nodes[0]) == null){
                ArrayList<Integer> tmp = new ArrayList<>();
                tmp.add(nodes[1]);
                graph.put(nodes[0],tmp);
            } else {
                graph.get(nodes[0]).add(nodes[1]);
            }
            if(graph.get(nodes[1]) == null){
                ArrayList<Integer> tmp = new ArrayList<>();
                tmp.add(nodes[0]);
                graph.put(nodes[1],tmp);
            } else {
                graph.get(nodes[1]).add(nodes[0]);
            }
        }
        int ans = 0;
        for(int i = 1 ; i <= N ; i++){
            if(isVisited[i]) continue;
            ans++;
            dfs(i);
        }
        System.out.println(ans);
    }

    private static void dfs(int cur) {
        ArrayList<Integer> tmp = graph.get(cur);
        if(tmp == null) return;
        for(int i = 0 ; i < tmp.size() ; i++){
            int next = tmp.get(i);
            if(isVisited[next]) continue;
            isVisited[next] = true;
            dfs(next);
        }
    }
}
