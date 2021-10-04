#include <iostream>
#include <queue>
#include <cstring>

#define MAX 201
#define INF 987654321

using namespace std;

int K;
int W,H;
int moveX[4] = {0,0,1,-1};
int moveY[4] = {1,-1,0,0};
int horseX[8] = {-2,-1,-2,-1,2,1,2,1};
int horseY[8] = {-1,-2,1,2,-1,-2,1,2};
bool isVisited[31][MAX][MAX];
int map[MAX][MAX];

int bfs(){
    queue<pair<int,pair<int,pair<int,int> > > > q;
    q.push(make_pair(0,make_pair(K,make_pair(0,0))));
    isVisited[K][0][0] = true;
    while(!q.empty()){
        int cnt = q.front().first; int k = q.front().second.first;
        int x = q.front().second.second.first; int y = q.front().second.second.second;
        q.pop();
        if(x == H - 1 && y == W - 1) return cnt;
        if(k > 0){
            for(int i = 0 ; i < 8 ; i++){
                int nX = horseX[i] + x; int nY = horseY[i] + y;
                if(nX < 0 || nX >= H || nY < 0 || nY >= W) continue;
                if(isVisited[k-1][nX][nY]) continue;
                if(map[nX][nY])  continue;
                isVisited[k-1][nX][nY] = true;
                q.push(make_pair(cnt+1,make_pair(k-1,make_pair(nX,nY))));
            }
        }
        for(int i = 0 ; i < 4 ; i++){
            int nX = moveX[i] + x; int nY = moveY[i] + y;
            if(nX < 0 || nX >= H || nY < 0 || nY >= W) continue;
            if(isVisited[k][nX][nY]) continue;
            if(map[nX][nY]) continue;
            isVisited[k][nX][nY] = true;
            q.push(make_pair(cnt+1,make_pair(k,make_pair(nX,nY))));
        }
    }

    return -1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;
    cin >> W >> H;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            cin >> map[i][j];
        }
    }

    memset(isVisited, false, sizeof(isVisited));
    int res = bfs();
    if(res == -1) cout << "-1\n";
    else cout << res << "\n";
}   