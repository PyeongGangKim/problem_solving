#include <iostream>
#include <queue>
#include <cstring>

#define MAX 21

using namespace std;

int map[MAX][MAX];
int check[MAX][MAX];
int N;
int size = 2;
int res = 0;
int eat = 0;
int moveX[4] = {-1,0,1,0};//위,왼,아,오
int moveY[4] = {0,-1,0,1};

void bfs(int x, int y){
    queue<pair<int, pair<int,int> > > q;
    q.push(make_pair(0,make_pair(x,y)));
    check[x][y] = true;
    map[x][y] = 0;
    while(!q.empty()){
        int time = q.front().first;
        int curX = q.front().second.first; int curY = q.front().second.second;
        q.pop();
        if(map[curX][curY] != 0 && map[curX][curY] < size){
            //먹고, 위치 스타트 위치 옮기고 시간 플러스
            int eatX = curX; int eatY = curY;
            
            eat++;
            if(eat == size){
                eat = 0;
                size++;
            }
            res += time;
            
            while(q.front().first > time){
                if(map[q.front().second.first][q.front().second.second] >= size || map[q.front().second.first][q.front().second.second] == 0) continue;
                if(eatX > q.front().second.first){
                    eatX = q.front().second.first;
                    eatY = q.front().second.second;
                }
                else if(eatX == q.front().second.first){
                    if(eatY > q.front().second.second){
                        eatX = q.front().second.first;
                        eatY = q.front().second.second;
                    }
                }
                q.pop();
            }
            while(!q.empty()) q.pop();
            cout << time << " " << size << " " << eatX << " " << eatY << " " << map[eatX][eatY] << "\n";
            map[eatX][eatY] = 0;
            q.push(make_pair(0, make_pair(eatX, eatY)));
            memset(check,false,sizeof(check));
            check[eatX][eatY] = true;
            map[eatX][eatY] = 0;
            continue;
        }
        for(int i = 0 ; i < 4 ; i++){
            int nextX = moveX[i] + curX; int nextY = moveY[i] + curY;
            if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) continue;
            if(check[nextX][nextY]) continue;
            check[nextX][nextY] = true;
            q.push(make_pair(time+1, make_pair(nextX, nextY)));
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N ;
    int startX, startY;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                startX = i;
                startY = j;
            }
        }
    }
    memset(check, false, sizeof(check));
    bfs(startX, startY);
    cout << res << "\n";
}