package 번14226;

import org.w3c.dom.Node;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static boolean[][] isVisited = new boolean[1001][1001];
    static int S;
    static class Node{
        int clipboard;
        int window;
        int time;

        public Node(int clipboard, int window, int time) {
            this.clipboard = clipboard;
            this.window = window;
            this.time = time;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        S = Integer.parseInt(br.readLine());
        for(int i = 0 ; i <= S ; i++){
            Arrays.fill(isVisited[i], false);
        }

        System.out.println(bfs());
    }

    private static int bfs() {
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(0,1,0));
        isVisited[1][0] = true;
        while(!q.isEmpty()){
            Node node = q.poll();

            if(node.window == S) return node.time;
            if(!isVisited[node.window][node.window]){
                q.add(new Node(node.window, node.window, node.time + 1));
                isVisited[node.window][node.window] = true;
            }

            if(node.window + node.clipboard <= S && !isVisited[node.window+ node.clipboard][node.clipboard]){
                q.add(new Node(node.clipboard, node.window + node.clipboard, node.time + 1));
                isVisited[node.window + node.clipboard][node.clipboard] = true;
            }

            if(node.window >= 1 && !isVisited[node.window - 1][node.clipboard]){
                q.add(new Node(node.clipboard, node.window - 1, node.time + 1));
                isVisited[node.window - 1][node.clipboard] = true;
            }
        }

        return -1;
    }


}
