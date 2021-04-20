#include <iostream>
#include <cstring>

using namespace std;
int map[51][51];

int moveX[4] = {-1,0,1,0};
int moveY[4] = {0,-1,0,1};
int backX[4] = {0,-1,0,1};
int backY[4] = {1,0,-1,0};
int N,M;
int cnt = 0;
int directionChange(int d){
    if(d==0) return 3;
    else if(d==1) return 0;
    else if(d==2) return 1;
    else return 2;
}
void solve(int y,int x,int d){
    
    int cnt = 0;
    int canNot = 0;
    while(1){
        int curD = d;
        int fourD = 4;
        bool canGo = false;
        int nextX;
        int nextY;
        while(fourD--){
            nextX = x+moveX[d] ; nextY = y+moveY[d];
            if(nextX >= 0 && nextY >=0 && nextX <= M-1 && nextY <= N-1 && map[nextY][nextX] == 0){
                canGo = true;
                break;
            }
            else{
                d = directionChange(d);
            }
        }
        if(canGo){
            cnt++;
            x = nextX; y = nextY;
            map[x][y] = 2;
            d = directionChange(d);
            cout << x << " " << y << " " << d << "\n";
        }
        else{
            d = curD;
            x = x - moveX[d] ; y = y - moveY[d];
            if(nextX < 0 || nextY < 0 || nextX >= M || nextY >= N || map[x][y] == 1) break;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int startX, startY, startD;
    cin >> startY >> startX >> startD;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> map[i][j];
        }
    }
    cnt++;
    map[startY][startX] = 2;
    solve(startY,startX,startD);
    cout << cnt << "\n";
}