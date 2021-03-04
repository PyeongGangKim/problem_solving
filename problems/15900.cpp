#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector<int> tree[500001];
int check[500001];
int result = 0;
void dfs(int n, int cnt){
    bool isLeaf = true;
    for(int i = 0 ; i < tree[n].size() ; i++){
        if(!check[tree[n][i]]){
            check[tree[n][i]] = true;
            isLeaf = false;
            dfs(tree[n][i], cnt+1);
        }
    }
    if(isLeaf) result += cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int nodeNum;
    cin >> nodeNum;
    int temp1, temp2;
    for(int i = 0 ; i < nodeNum - 1 ; i++){
        cin >> temp1 >> temp2;
        tree[temp1].push_back(temp2);
        tree[temp2].push_back(temp1);
    }
    memset(check, false, sizeof(check));
    check[1] = true;
    dfs(1, 0);
    if(result % 2 == 0) cout << "No" << "\n";
    else cout << "Yes" << "\n";
}