#include <iostream>
#include <vector>

using namespace std;

int searchNode[100001] = {0,};
vector<int> tree[100001];
int num;

void dfs(int n){
    for(int i = 0 ; i < tree[n].size() ; i++){
        int node = tree[n][i];
        if(searchNode[node] == 0){
            searchNode[node] = n;
            dfs(node);
        }
    }
}   
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> num;
    int temp1, temp2;
    for(int i = 0 ; i < num - 1; i++){
        cin >> temp1 >> temp2;
        tree[temp1].push_back(temp2);
        tree[temp2].push_back(temp1);
    }
    dfs(1);
    for(int i = 2 ; i <= num ; i++) {
        cout << searchNode[i] << "\n";
    }
}