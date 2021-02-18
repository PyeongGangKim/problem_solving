#include <iostream>


using namespace std;

int N;
int map[16][16] = {0, };

int cnt = 0;

int xCheck[3] = {1,1,0};
int yCheck[3] = {0,1,1};

void dfs(int y, int x, int dir){
    int nx,ny;
    if(x == N-1 && y == N-1) {
        cnt++; 
        return;
    }
    if(dir == 0){//가로
        for(int i = 0 ; i < 2 ; i++){
            nx = x + xCheck[i]; ny = y + yCheck[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(map[ny][nx] == 1) continue;
            dfs(ny,nx,i);
        }
    }
    else if(dir == 1){ //대각선
        for(int i = 0 ; i < 3 ; i++){
            nx = x + xCheck[i]; ny = y + yCheck[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(map[ny][nx] == 1 || map[y+1][x] == 1 || map[y][x+1] == 1)  continue;
            dfs(ny,nx,i);
        }

    }
    else{// 세로
        for(int i = 1 ; i < 3 ; i++){
            nx = x + xCheck[i]; ny = y + yCheck[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(map[ny][nx] == 1) continue;
            dfs(ny,nx,i);
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> map[i][j];
        }
    }
    dfs(0,1,0);
    cout << cnt << "\n";
}