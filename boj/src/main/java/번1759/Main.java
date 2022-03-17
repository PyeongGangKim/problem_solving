package 번1759;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;

public class Main {
    static int minM, maxM;
    static String[] alphabets;
    static String[] vowels = {"a", "e", "i", "o", "u"};
    static int L, C;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] input = Arrays.stream(br.readLine().split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();
        L = input[0]; C = input[1];
        minM = 1; maxM = L - 2;
        alphabets = br.readLine().split(" ");
        Arrays.sort(alphabets);
        dfs(0, 0, new Stack<String>());
    }

    static void dfs(int idx, int curM, Stack<String> cur){
        if(curM >= minM && curM <= maxM && cur.size() == L){
            printResult(cur);
        } else{
            for(int i = idx ; i < C ; i++){
                if(curM > maxM || (curM == maxM && isVowel(i))) continue;
                int nextM = curM;
                if(isVowel(i)) nextM++;
                cur.push(alphabets[i]);
                dfs(i + 1, nextM, cur);
                cur.pop();
            }
        }

    }

    private static boolean isVowel(int i) {
        for (String vowel : vowels) {
            if (vowel.equals(alphabets[i])) {
                return true;
            }
        }
        return false;
    }


    private static void printResult(Stack<String> cur) {
        String print = "";
        for (String s : cur) {
            print += s;
        }
        System.out.println(print);
    }
}
