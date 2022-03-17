package 오등큰수;

import java.util.*;

public class Main {

    /*
    * 수열의 각 원소 Ai에 대해서 오등큰수 NGF(i)를 구하려고 한다.
    * Ai가 수열 A에서 등장한 횟수를 F(Ai)라고 했을 때, Ai의 오등큰수는 오른쪽에 있으면서 수열 A에서 등장한 횟수가 F(Ai)보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다.
    * 그러한 수가 없으면 오등 큰수는 -1
    * 오등 큰수는 등장한 횟수가 선택된 숫자보다 큰 수중에서 가장 왼쪽에 있는 수. 그리고 현재 선택된 수보다 오른쪽에 있어야됨.
    * map으로 각 숫자가 몇번 나왔는지 체크
    * 그리고 하나씩 검사하면 n^2
    * priority queue를 사용해서 뒤에서 부터 계산하고 top에
    * */

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine());
        Stack<Integer> st = new Stack<>();

        Map<Integer, Integer> hm = new HashMap<Integer, Integer>();
        int[] nums = Arrays.stream(sc.nextLine().split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();

        for(int num : nums){
            if(hm.get(num) == null){
                hm.put(num,1);
            } else {
                hm.put(num, hm.get(num) + 1);
            }
        }

        int[] result = new int[nums.length];

        for(int i = 0 ; i < nums.length ; i++){
            while(!st.isEmpty() && hm.get(nums[st.peek()]) < hm.get(nums[i])){
                result[st.pop()] = nums[i];
            }
            st.push(i);
        }

        while(!st.isEmpty()){
            result[st.pop()] = -1;
        }

        StringBuilder sb = new StringBuilder();
        for (int res : result) {
            sb.append(res+ " ");
        }
        System.out.println(sb.toString());
    }


}
