#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<int, int > > node[100001];
bool check[100001];
int maxNum = -1;
int maxNode = 0;

void dfs(int n , int pastLength ){
    if(check[n]) return;
    check[n] = true;

    if(maxNum < pastLength){
        maxNum = pastLength;
        maxNode = n;
    }

    for(int i = 0 ; i < node[n].size() ; i++){
        dfs(node[n][i].first, pastLength + node[n][i].second);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int nodeNum;
    cin >> nodeNum;
    int fromNode, toNode, dist;
    for(int i = 0 ; i < nodeNum-1 ; i++ ){
        cin >> fromNode >> toNode >> dist;
        node[fromNode].push_back(make_pair(toNode,dist));
        node[toNode].push_back(make_pair(fromNode,dist));
    }
    memset(check, false, sizeof(check));
    dfs(1,0);
    memset(check, false, sizeof(check));
    maxNum = 0;
    dfs(maxNode, 0);
    cout << maxNum << "\n";

}