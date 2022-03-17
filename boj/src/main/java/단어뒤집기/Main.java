package 단어뒤집기;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/*
* 인풋을 token으로 나눈 후 하나씩 뒤집으면 될
* */
public class Main {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int num = Integer.parseInt(sc.nextLine());

        for(int i = 0 ; i < num ; i++){
            String[] words = sc.nextLine().split(" ");
            reverseWord(words);
            System.out.println();
        }
    }

    private static void reverseWord(String[] words) {
        for(String word : words){
            System.out.print(new StringBuffer(word).reverse().toString() + " ");
        }
    }


}
