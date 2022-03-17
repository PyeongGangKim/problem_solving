package sk;

import java.util.ArrayList;
import java.util.Collections;

public class 번1 {
    static int[] coin = {1,5,10,50,100,500};
    static class Value implements Comparable<Value>{
        double val;
        int coin;
        int cost;

        public Value(double val, int coin, int cost) {
            this.val = val;
            this.coin = coin;
            this.cost = cost;
        }

        @Override
        public int compareTo(Value o){
            if(this.val < o.val) return -1;
            else return 1;

        }


    }
    static class Solution {
        static public int solution(int money, int[] costs) {
            ArrayList<Value> list = new ArrayList<>();
            for(int i = 0 ; i < 6 ; i++){
                list.add(new Value((double) costs[i] / coin[i], coin[i], costs[i]));
            }
            int answer = 0;
            Collections.sort(list);
            int idx = 0;
            for (Value value : list) {
                System.out.println("value.coin + \" \" + value.cost = " + value.coin + " " + value.cost);
            }

            while(money != 0){
                int tmp = money / list.get(idx).coin;
                answer += tmp * list.get(idx).cost;
                money = money - tmp * list.get(idx).coin;
                idx++;
            }

            return answer;
        }
    }

    public static void main(String[] args) {
        Solution.solution(4578,new int[]{1,4,99,35,50,1000});
    }
}
