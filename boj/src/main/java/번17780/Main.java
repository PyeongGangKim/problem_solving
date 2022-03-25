package 번17780;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[][] map;
    static LinkedList<Horse>[][] chessHorse;

    static class Horse implements Comparable<Horse>{
        int num;
        int n,m;
        int dir;

        public Horse(int n, int m, int dir, int num) {
            this.n = n;
            this.m = m;
            this.dir = dir;
            this.num = num;
        }

        @Override
        public int compareTo(Horse o) {
            return this.num - o.num ;
        }

    }
    static int N,K;
    static PriorityQueue<Horse> order;
    static int[] mN = {0,0,-1,1};
    static int[] mM = {1,-1,0,0};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        chessHorse = new LinkedList[N][N];
        order = new PriorityQueue<>();
        map = new int[N][N];
        for(int i = 0 ; i < N ; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j < N ; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                chessHorse[i][j] = new LinkedList<>();
            }
        }
        for (int i = 0 ; i < K ; i++){
            st = new StringTokenizer(br.readLine());
            Horse tmp = new Horse(Integer.parseInt(st.nextToken()) - 1, Integer.parseInt(st.nextToken()) - 1, Integer.parseInt(st.nextToken()) - 1, i);
            chessHorse[tmp.n][tmp.m].add(tmp);
        }
        pushHorseToOrder();
        // 방향 바꿀 땐,
        int ans = 0;
        while(ans <= 1000){
            if(checkGameDone()) break;
            ans++;
            while(!order.isEmpty()){
                Horse cur = order.poll();
                //처음에는 무조건 흰색이기 때문에 움직여도 됨
                int nextN = cur.n + mN[cur.dir]; int nextM = cur.m + mM[cur.dir];
                if(nextN < 0 || nextN >= N || nextM < 0 || nextM >= N || map[nextN][nextM] == 2){ // 넘어가는 경우 방향만 바꾸기, 파란색일 경우,
                    // 그 다음 갈 곳의 값이 바깥이 아니고, 파란색이 아니면 order에 넣어주고 아니면 넣어주지 않기
                    int changedDir = changeDir(cur.dir);
                    chessHorse[cur.n][cur.m].getFirst().dir = changedDir;
                    int checkN = cur.n + mN[changedDir]; int checkM = cur.m + mM[changedDir];
                    if(checkN >= 0 && checkN < N && checkM >= 0 && checkM < N && map[checkN][checkM] != 2) order.add(cur);
                } else if(map[nextN][nextM] == 1){//빨간색일 경우
                    //말이 없는 경우는 이동한 후 순서를 바꾼다. 근데, 만약 순서 바꿨는데, 현재 num보다 큰 수가 맨아래면 order에 넣어주기
                    //말이 있는 경우에는 그냥 순서만 바꿔서 저장하면 됨.
                    if(chessHorse[nextN][nextM].isEmpty()) {
                        //순서 변경
                        //이전에 있는 거 뒤에서 부터 넣어주고, cur은 clear
                        reverseStackHorse(cur.n, cur.m, nextN, nextM);
                        //cur의 num과 바꾼 순서의 num을 비교해줘서 넣기
                        if(cur.num < chessHorse[nextN][nextM].getFirst().num){
                            order.add(chessHorse[nextN][nextM].getFirst());
                        }
                    } else { //말이 있는 경우에는 순서만 바꾸기
                        reverseStackHorse(cur.n, cur.m, nextN, nextM);
                    }
                } else { // 흰색일 경우
                    //그냥 쌓아주면 됨.
                    stackHorse(cur.n, cur.m, nextN, nextM);
                }
            }
            pushHorseToOrder();
        }

        if(ans > 1000)
            System.out.println("-1");
        else
            System.out.println(ans);
    }

    private static boolean checkGameDone() {
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(chessHorse[i][j].size() >= 4) return true;
            }
        }
        return false;
    }

    private static void stackHorse(int curN, int curM, int nextN, int nextM) {
        Iterator<Horse> iterator = chessHorse[curN][curM].iterator();
        while(iterator.hasNext()){
            Horse tmp = iterator.next();
            tmp.n = nextN; tmp.m = nextM;
            chessHorse[nextN][nextM].add(tmp);
        }
        chessHorse[curN][curM].clear();
    }

    private static void reverseStackHorse(int curN, int curM, int nextN, int nextM) {
        Iterator<Horse> iterator = chessHorse[curN][curM].descendingIterator();
        while(iterator.hasNext()) {
            Horse tmp = iterator.next();
            tmp.n = nextN; tmp.m = nextM;
            chessHorse[nextN][nextM].add(tmp);
        }
        chessHorse[curN][curM].clear();
    }

    private static int changeDir(int dir) {
        if(dir == 0) return 1;
        else if(dir == 1) return 0;
        else if(dir == 2) return 3;
        else return 2;
    }

    private static void pushHorseToOrder() {
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(!chessHorse[i][j].isEmpty()){
                    order.add(chessHorse[i][j].getFirst());
                }
            }
        }
    }
}
