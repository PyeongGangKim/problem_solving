#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

queue<pair<int, int> > q;
bool check[1000][1000];
int map[1000][1000];
int N, M;
int xMove[4] = {0,1,-1,0};
int yMove[4] = {1,0,0,-1};
bool bfs(int m, int n){
    q.push(make_pair(m,n));
    check[m][n] = true;
    while(!q.empty()){
        int cM = q.front().first; int cN = q.front().second;
        q.pop();
        if(cM == M-1) return true;
        for(int i = 0 ; i < 4 ; i++){
            int nM = cM + yMove[i]; int nN = cN + xMove[i];
            if(nM < 0 || nM >= M || nN < 0 || nN >= N) continue;
            if(check[nM][nN] || map[nM][nN]) continue;
            q.push(make_pair(nM, nN));
            check[nM][nN] = true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> M >> N;
    string temp;
    for(int i = 0 ; i < M ; i++){
        cin >> temp;
        for(int j = 0 ; j < N ; j++){
            map[i][j] = temp[j] - '0';
        }
    }
    for(int i = 0 ; i < N ; i++){
        if(map[0][i]) continue;
        memset(check, false, sizeof(check));
        if(bfs(0,i)){
            cout << "YES" << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
}