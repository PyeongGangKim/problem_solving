package 번1748;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        //String res = ""; //메모리 초과
        long res = 0L;
        for(int i = 1 ; i <= N ; i++){
            int tmp = i;
            int plus = 1;
            while(tmp/10 != 0){
                plus++;
                tmp /= 10;
            }
            res += plus;
        }
        System.out.println(res);
    }
}
