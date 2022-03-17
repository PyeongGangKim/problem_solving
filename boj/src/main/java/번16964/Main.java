package 번16964;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static ArrayList<Integer>[] map;
    static int[] dfsOrder;
    static boolean[] isVisited;
    static class Node{
        int parent, childSize;

        public Node(){
            parent = 0;
            childSize = 0;
        }
        public Node(int parent, int childSize) {
            this.parent = parent;
            this.childSize = childSize;
        }
    }
    static Node[] nodes;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        map = new ArrayList[N+1];
        isVisited = new boolean[N+1];
        dfsOrder = new int[N+1];
        nodes = new Node[N+1];
        for(int i = 0 ; i <= N ; i++){
            map[i] = new ArrayList<>();
            nodes[i] = new Node();
        }

        for(int i = 0 ; i < N - 1 ; i++){
            st = new StringTokenizer(br.readLine());
            int n1 = Integer.parseInt(st.nextToken()); int n2 = Integer.parseInt(st.nextToken());
            map[n1].add(n2);
            map[n2].add(n1);
        }
        Arrays.fill(isVisited,false);
        dfs(1);
        st = new StringTokenizer(br.readLine());
        for(int i = 0 ; i < N  ; i++){
            dfsOrder[i] = Integer.parseInt(st.nextToken());
        }
        int parent = 1;
        boolean isPossible = true;
        for(int i = 1 ; i < N ; i++){
            int cur = dfsOrder[i];
            if(nodes[cur].parent == parent){
                nodes[parent].childSize--;
                if(nodes[cur].childSize != 0){
                    parent = cur;
                } else if(nodes[cur].childSize == 0 && i != N - 1){
                    while(nodes[parent].childSize == 0){
                        parent = nodes[parent].parent;
                    }
                }
            }
            else{
                isPossible = false;
                break;
            }
        }
        if(isPossible) System.out.println("1");
        else System.out.println("0");
    }

    private static void dfs(int cur) {
        isVisited[cur] = true;
        for (Integer next : map[cur]) {
            if(isVisited[next]) continue;
            nodes[cur].childSize++;
            nodes[next].parent = cur;
            dfs(next);
        }
    }
}
