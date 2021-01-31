#include <iostream>
#include <algorithm>

using namespace std;

int xCheck[4] = {-1,0,0,1};
int yCheck[4] = {0,-1,1,0};

int maxScore = -1;
int X, Y;
bool check[500][500] = {false, };
int map[500][500] = {0, };

void dfs(int x, int y, int level, int score){
    if(level == 4){
        maxScore = max(maxScore, score);
    }
    else{
        for(int i = 0 ; i < 4 ; i++){
            int nX = x + xCheck[i]; int nY = y + yCheck[i];
            if(nX < 0 || nY < 0 || nX >= X || nY >= Y) continue;
            if(check[nY][nX]) continue;
            check[nY][nX] = true;
            dfs(nX, nY, level + 1, map[nY][nX] + score);
            check[nY][nX] = false;
        }
    }
}

void otherCase(int x, int y){
    int score;
    if(x + 2 < X && y - 1 >= 0){
        score = map[y][x] + map[y][x+1] + map[y][x+2] + map[y-1][x+1];
        maxScore = max(score, maxScore);
        
    }
    if(x + 1 < X && y + 2 < Y){
        score = map[y][x] + map[y+1][x] + map[y+1][x+1] + map[y+2][x];
        maxScore = max(score, maxScore);
        
    }
    if(x + 2 < X && y + 1 < Y){
        score = map[y][x] + map[y][x+1] + map[y][x+2] + map[y+1][x+1];
        maxScore = max(score, maxScore);
        
    }
    if(x - 1 >= 0 && y + 2 < Y){
        score = map[y][x] + map[y+1][x] + map[y+1][x-1] + map[y+2][x];
        maxScore = max(score, maxScore);
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> Y >> X;
    for(int i = 0 ; i < Y ; i++){
        for(int j = 0 ; j < X ; j++){
            cin >> map[i][j];
            
        }
    }

    for(int i = 0 ; i < Y ; i++){
        for(int j = 0 ; j < X ; j++){
            check[i][j] = true;
            dfs(j,i,1,map[i][j]);
            check[i][j] = false;
            otherCase(j,i);
        }
    }
    cout << maxScore << "\n";
}

