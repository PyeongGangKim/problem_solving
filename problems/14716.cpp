#include <iostream>
#include <cstring>

using namespace std;

bool check[250][250];
int map[250][250];
int wordCnt = 0;
int N, M;
int moveX[9] = {-1,0,1,-1,0,1,-1,0,1};
int moveY[9] = {-1,-1,-1,0,0,0,1,1,1};

void search(int x, int y){
    for(int i = 0 ; i < 9 ; i++){
        int nextX = x + moveX[i]; int nextY = y + moveY[i];
        if(nextX < 0 || nextY < 0 || nextX >= N || nextY >= M) continue;
        if(check[nextY][nextX] || map[nextY][nextX] == 0) continue;
        check[nextY][nextX] = true;
        search(nextX, nextY);
    }
}

void dfs(){
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            if(!check[i][j] && map[i][j] == 1){
                wordCnt++;
                check[i][j] = true;
                search(j,i);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> map[i][j];
        }
    }
    memset(check, false, sizeof(check));
    dfs();
    cout << wordCnt << "\n";
}