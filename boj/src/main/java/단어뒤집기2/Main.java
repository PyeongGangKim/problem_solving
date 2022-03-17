package 단어뒤집기2;

import java.util.*;
/*
* tag안에 있는 단어는 무시
* stack으로 풀자
* 띄어쓰기가 나오기 또는 < 가 나오기 전까지 stack에 넣기
* 그리고 위에 띄어쓰기나 <가 나오면 pop
* <가 나오면 >까지 계속 그냥 출력
* */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String words = sc.nextLine();
        Stack<Character> st = new Stack<>();
        boolean isTag = false;
        String word = "";
        for(int i = 0 ; i < words.length() ; i++){
            if(words.charAt(i) == '>'){
                word += words.charAt(i);
                System.out.print(word);
                word = "";
                isTag = false;
            } else if(words.charAt(i) == '<' || words.charAt(i) == ' '){
                while(!st.isEmpty()){
                    word += st.pop();
                }
                System.out.print(word);
                word = words.charAt(i)+"";
                if(words.charAt(i) == '<') isTag = true;
            } else {
                if(isTag) word += words.charAt(i);
                else st.push(words.charAt(i));
            }
        }
        if(!st.isEmpty()){
            while(!st.isEmpty()){
                word += st.pop();
            }
            System.out.print(word);
        }
    }
}
