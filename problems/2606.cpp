#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> computer[101];
bool check[101];
int cnt = 0;
void dfs(int n){
    for(int i = 0 ; i < computer[n].size() ; i++){
        if(!check[computer[n][i]]){
            check[computer[n][i]] = true;
            cnt++;
            dfs(computer[n][i]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int nodeNum, edgeNum;
    cin >> nodeNum;
    cin >> edgeNum;
    int temp1, temp2;
    for(int i = 0 ; i < edgeNum ; i++){
        cin >> temp1 >> temp2;
        computer[temp1].push_back(temp2);
        computer[temp2].push_back(temp1);
    }
    memset(check,false,sizeof(check));
    check[1] = true;
    dfs(1);
    cout << cnt << "\n";
}