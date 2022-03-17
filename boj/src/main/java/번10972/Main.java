package 번10972;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int[] nums;
    static int N;
    static boolean next = false;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        nums = Arrays.stream(br.readLine().split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();

        if(!permutation()) System.out.println("-1");
        else{
            String res = "";
            for (int num : nums) {
                res += Integer.toString(num) + " ";
            }
            System.out.println(res);
        }
    }

    private static boolean permutation() {
        int i = nums.length-1;
        while(i > 0 && nums[i] < nums[i-1]) {
            i--;
        }

        if(i == 0) //마지막 순열인 경우
            return false;

        int j = nums.length-1;
        while(nums[i-1] > nums[j]) {
            j--;
        }
        swap(i-1, j);

        j = nums.length-1;
        while(i < j) {
            swap(i, j);
            i++;
            j--;
        }

        return true;
    }

    static void swap( int a , int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}
