package 네수;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nums = br.readLine().split(" ");

        long AB = Long.parseLong(nums[0] + nums[1]);
        long CD = Long.parseLong(nums[2] + nums[3]);

        long res = AB + CD;
        System.out.println(res);
    }
}
