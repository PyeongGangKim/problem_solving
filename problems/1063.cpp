#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
int N, K;
vector<string> words;
vector<char> v;
bool alpha_check[26];
bool picked_alpha[26];
int maxNum = 0;
int check_word(){
    int cnt = 0;
    for(int i = 0 ; i < words.size() ; i++){
        bool isPossible = true;
        for(int j = 4 ; j < words[i].length() - 4 ; j++){
            if(!picked_alpha[words[i][j] - 'a']){
                isPossible = false;
                break;
            }
        }
        if(isPossible) cnt++;
    }
    return cnt;
}
void dfs(int cnt, int n){
    if(cnt == K - 5 || v.size() <= cnt){
        maxNum = max(check_word(), maxNum);
    }
    else{
        for(int i = n ; i < v.size() ; i++){
            if(!picked_alpha[v[i] - 'a']){
                picked_alpha[v[i] - 'a'] = true;
                dfs(cnt+1, i);
                picked_alpha[v[i] - 'a'] = false;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> K;
    
    memset(alpha_check, false, sizeof(alpha_check));
    memset(picked_alpha, false, sizeof(picked_alpha));
    alpha_check['a' - 'a'] = true, alpha_check['n' - 'a'] = true, alpha_check['i' - 'a'] = true, alpha_check['t' - 'a'] = true, alpha_check['c' - 'a'] = true;
    picked_alpha['a' - 'a'] = true, picked_alpha['n' - 'a'] = true, picked_alpha['i' - 'a'] = true, picked_alpha['t' - 'a'] = true, picked_alpha['c' - 'a'] = true;

    for(int i = 0 ; i < N ; i++){
        string temp;
        cin >> temp;
        words.push_back(temp);
        for(int j = 0 ; j < temp.length() ; j++){
            int num = temp[j] - 'a';
            if(!alpha_check[num]){
                alpha_check[num] = true;
                v.push_back(temp[j]);
            }
        }
    }
    if(K - 5 < 0) cout << "0\n";
    else if(K == 5) cout << check_word() << "\n";
    else{
        dfs(0,0);
        cout << maxNum << "\n";
    }
    
}