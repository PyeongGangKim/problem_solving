#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

string input;
unordered_set<string> um;

void dfs(string str, int idx){
    um.insert(str);
    if(idx < input.length()){
        dfs(str + input[idx], idx+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> input;

    for(int i = 0 ; i < input.length() ; i++){
        string temp = "";
        temp += input[i];
        dfs(temp, i+1);
    }
    cout << um.size() << "\n";
}