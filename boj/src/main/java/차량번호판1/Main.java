package 차량번호판1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    /*
    * 번호판에 사용할 ㅅ ㅜ있는 숫자는 0~9
    * 문자는 a~z
    * 최대 4글자 c와 d로 이뤄진 문자열로 나타낼 수 있다.
    * c는 문자가 위치하는 자리, d는 숫자가 위치하는 자리
    * 같은 문자 or 숫자가 연속해서 2번 나타나면 안된다.
    * 가능한 차량 번호판의 개수
    * brute force 이전의 값을 체크해서 보면 될
    * */
    static int answer = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = "";
        input = br.readLine();
        dfs(input, new ArrayList<String>() , 0);
        System.out.println(answer);

    }

    static void dfs(String pattern, List<String> cur, int idx){

        if(pattern.length() == idx) answer++;
        else{
            if(pattern.charAt(idx) == 'd'){
                if(idx == 0){
                    for (int i = 0 ; i < 10 ; i++){
                        cur.add(Integer.toString(i));
                        dfs(pattern,cur,idx+1);
                        cur.remove(idx);
                    }
                }
                else{
                    for(int i = 0 ; i < 10 ; i++){
                        if(cur.get(idx-1).equals(Integer.toString(i))) continue;
                        cur.add(Integer.toString(i));
                        dfs(pattern,cur,idx+1);
                        cur.remove(idx);
                    }
                }
            }
            else{
                if(idx == 0){
                    for (char i = 'a' ; i <= 'z' ; i++){
                        cur.add(Integer.toString(i));
                        dfs(pattern,cur,idx+1);
                        cur.remove(idx);
                    }
                }
                else{
                    for(int i = 'a' ; i <= 'z' ; i++){
                        if(cur.get(idx-1).equals(Integer.toString(i))) continue;
                        cur.add(Integer.toString(i));
                        dfs(pattern,cur,idx+1);
                        cur.remove(idx);
                    }
                }
            }
        }
    }
}
