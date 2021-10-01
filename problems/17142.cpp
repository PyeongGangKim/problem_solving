#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
#define INF 1e9
int N, M;
vector<pair<int,int> > virus;
int map[51][51];
int res = INF;
int zeroNum = 0;
int check[51];
int visited[51][51];

int moveX[4] = {0,0,1,-1};
int moveY[4] = {1,-1,0,0};

void bfs(){
    queue<pair<int,int> > q;
    memset(visited, -1, sizeof(visited));
    for(int i = 0 ; i < virus.size() ; i++){
        if(check[i]){
            q.push(make_pair(virus[i].first,virus[i].second));
            visited[virus[i].first][virus[i].second] = 0;
        }
    }
    int time = 0; int check = 0;
    while(!q.empty()){
        int x = q.front().first; int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nX = moveX[i] + x; int nY = moveY[i] + y;
            if(nX < 0 || nX >= N || nY < 0 || nY >= N) continue;
            if(map[nX][nY] != 1 && visited[nX][nY] == -1){
                visited[nX][nY] = visited[x][y] + 1;
                if(map[nX][nY] == 0){
                    time = visited[nX][nY];
                    check++;
                }
                q.push(make_pair(nX, nY));
            }
        }
    }
    if(check == zeroNum) res = min(res, time);
} 

void virus_pick(int cnt, int idx){
    if(cnt == M){
        bfs();
    }
    else{
        for(int i = idx ; i < virus.size() ; i++){
            if(!check[i]){
                check[i] = true;
                virus_pick(cnt+1 , i+1);
                check[i] = false;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> map[i][j];
            if(map[i][j] == 2) virus.push_back(make_pair(i,j));
            if(map[i][j] == 0) zeroNum++;
        }
    }
    virus_pick(0,0);
    if(res == INF) cout << "-1\n";
    else cout << res << "\n";
}