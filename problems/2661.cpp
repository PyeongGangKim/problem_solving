#include <iostream>
#include <string>

using namespace std;

int N;
bool isDone = false;

bool isValid(string str, int len){
    int size = str.length();
    for(int i = 1 ; i <= len/2 ; i++){
        if(str.substr(size - i, i) == str.substr(size - i*2, i)) return false;
    }
    return true;
}
void dfs(string str, int len){
    if(isDone) return;
    if(!isValid(str,len) && len != 0){
        return;
    }
    if(len == N){
        cout << str << "\n";
        isDone = true;
        return;
    }
    dfs(str + "1", len + 1);
    dfs(str + "2", len + 1);
    dfs(str + "3", len + 1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;
    cin >> N;
    dfs(s,0);
}