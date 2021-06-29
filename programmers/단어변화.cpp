#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
int check[51];
int result = 987654321;
bool oneAlphaDif(string str1 ,string str2){
    int cnt = 0;
    for(int i = 0 ; i < str1.length() ; i++){
        if(str1[i] != str2[i]) cnt++;
    }
    if(cnt == 1) return true;
    else return false;
}
void dfs(int cnt, string word, string target, vector<string> words){
    if(word == target){
        result = min(result, cnt);
    }
    else{
        for(int i = 0 ; i < words.size() ; i++){
            if(!check[i] && oneAlphaDif(word, words[i])){
                check[i] = true;
                dfs(cnt + 1, words[i], target, words);
                check[i] = false;
            }
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    memset(check, false, sizeof(check));
    dfs(0, begin, target, words);
    if(result == 987654321) result = 0;
    answer = result;
    return answer;
}