#include <iostream>
#include <queue>
#include <cstring>
#include <string>

#define MAX 1000

using namespace std; 

bool cache[MAX][MAX][11];
int map[MAX][MAX];
int N,M,K;
int nMove[4] = {0,0,1,-1};
int mMove[4] = {1,-1,0,0};
struct node{
    int n,m;
    int rem, num;
};

int bfs(){
    queue<node> q;
    node sNode;
    sNode.n = 0; sNode.m = 0; sNode.rem = K; sNode.num = 1;
    cache[0][0][K] = true;
    q.push(sNode);
    while(!q.empty()){
        node temp = q.front();
        int n = temp.n ; int m = temp.m; int rem = temp.rem; int num = temp.num;
        q.pop();
        if(n == N-1 && m == M-1){
            return num;
        }
        for(int i = 0 ; i < 4 ; i++){
            int nN = n + nMove[i] ; int nM = m + mMove[i];
            
            if(nN < 0 || nN > N-1 || nM < 0 || nM > M-1) continue;
            if(cache[nN][nM][rem]) continue;
            if(map[nN][nM] == 1 && rem != 0 && !cache[nN][nM][rem-1]){
                cache[nN][nM][rem-1] = true;
                node pushNode;
                pushNode.n = nN; pushNode.m = nM; pushNode.rem = rem - 1; pushNode.num = num + 1;
                q.push(pushNode);
            }
            if(map[nN][nM] == 0){
                cache[nN][nM][rem] = true;
                node pushNode;
                pushNode.n = nN; pushNode.m = nM; pushNode.rem = rem; pushNode.num = num + 1;
                q.push(pushNode);
            }
        }

    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    memset(cache, false, sizeof(cache));
    cin >> N >> M >> K;
    string str;
    for(int i = 0 ; i < N ; i++){
        cin >> str;
        for(int j = 0 ; j < M ; j++){
            map[i][j] = str[j] - '0';
        }
    }
    cout << bfs() << "\n";
}