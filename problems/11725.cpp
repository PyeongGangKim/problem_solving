#include <iostream>

using namespace std;

int searchNode[100001] = {0,};
bool tree[100001][100001] = {false, };
int num;

void dfs(int n){
    for(int i = 1 ; i <= num ; i++){
        if(tree[n][i] && searchNode[i] == 0){
            searchNode[i] = n;
            dfs(i);
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
        tree[temp1][temp2] = true;
        tree[temp2][temp1] = true;
    }
    dfs(1);
    for(int i = 2 ; i <= num ; i++) {
        cout << searchNode[i] << "\n";
    }
}