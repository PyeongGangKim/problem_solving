#include <iostream>
#include <cstring>
#include <unordered_set>
#include <string>

using namespace std;
bool check[9];
string N;
unordered_set<string> us;

void dfs(string str, string order){
    if(str.length() == N.length()){
        if(str.compare(N) == 0){
            us.insert(order);
        }
    }else{
        for(int i = 0 ; i < N.length(); i++){
            if(check[i]) continue;
            check[i] = true;
            dfs(str + N[i], order + str + N[i]);
            dfs(N[i] + str, order + str + N[i]);
            check[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    memset(check, false, sizeof(check));
    for(int i = 0 ; i < N.size(); i++){
        check[i] = true;
        string push = "";
        push += N[i];
        dfs(push, push);
        check[i] = false;
    }
    cout << us.size() << "\n";
}
