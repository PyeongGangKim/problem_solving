#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
vector<int> tree[1000001];
vector<int> dfs[1000001];
int dp[1000001][2];
int isVisited[1000001] = {false,};

void DFS(int node){
    isVisited[node] = true;
    for(int i = 0 ; i < tree[node].size() ; i++){
        int next = tree[node][i];
        if(isVisited[next]) continue;
        dfs[node].push_back(next);
        DFS(next);
    }
}
int earlyAdaptor(int node, bool isAdaptor){
    int& res = dp[node][isAdaptor];
    if(res != -1) return res;

    if(isAdaptor){
        res = 1;
        for(int i = 0 ; i < dfs[node].size() ; i++){
            res += min(earlyAdaptor(dfs[node][i], true), earlyAdaptor(dfs[node][i], false));
        }
    }
    else{
        res = 0;
        for(int i = 0 ; i < dfs[node].size() ; i++){
            res += earlyAdaptor(dfs[node][i], true);
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N;
    for(int i = 0 ; i < N-1 ; i++){
        int node1, node2;
        cin >> node1 >> node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }
    memset(dp, -1, sizeof(dp));
    memset(isVisited, false, sizeof(isVisited));
    DFS(1);
    cout << min(earlyAdaptor(1, true), earlyAdaptor(1, false)) << "\n";

}