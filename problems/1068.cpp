#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[51];
int leafNum[51];
int dfs(int n, int deleteNode){
    int cnt = 0;
    if(n == deleteNode ) return cnt;
    for(int i = 0 ; i < tree[n].size() ; i++){
        cnt += dfs(tree[n][i], deleteNode);
    }
    if(cnt == 0) cnt = 1;
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int nodeNum, root, deleteNode;
    cin >> nodeNum;
    int temp;
    for(int i = 0 ; i < nodeNum ; i++){
        cin >> temp;
        if(temp == -1) root = i;
        else tree[temp].push_back(i);
    }
    cin >> deleteNode;
    
    cout << dfs(root, deleteNode) << "\n";

}