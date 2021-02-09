#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int check[1001] = {0, };
int graph[1001][1001] = {0, };

int node, startNode;
queue<int> q;
void DFS(int n){
    cout << n << " ";
    for(int i = 1 ; i <= node ; i++){
        if(graph[n][i] == 1 && check[i] == 0){
            check[i] = 1;
            DFS(i);
        }
    }
}
void BFS(){
    while(!q.empty()){
        int n = q.front();
        cout << n << " ";
        q.pop();
        for(int i = 1 ; i <= node ; i++){
            if(graph[n][i] == 1 && check[i] == 0){
                check[i] = 1;
                q.push(i);
            }
        }
    }
}

void solve(){
    check[startNode] = 1;
    DFS(startNode);
    cout << "\n";
    memset(check, 0 , sizeof(check));
    check[startNode] = 1;
    q.push(startNode);
    BFS();
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int edge;
    cin >> node >> edge >> startNode;
    int temp1, temp2;
    for(int i = 0 ; i < edge ; i++){
        cin >> temp1 >> temp2;
        graph[temp1][temp2] = 1;
        graph[temp2][temp1] = 1;
    }
    solve();
}