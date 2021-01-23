#include <iostream>
#include <queue>

using namespace std;

int mapSize;
int map[100][100];
int checkNormal[100][100] = {0, };
int checkUnNormal[100][100] = {0, };
int cntNormal = 0;
int cntUnNormal = 0;

int xCheck[4] = {-1,0,0,1};
int yCheck[4] = {0,-1,1,0};

void searchNormal(int x, int y){
    int nextX, nextY;
    for(int i = 0 ; i < 4 ; i++){
        nextX = x + xCheck[i]; nextY = y + yCheck[i];
        if(nextX >= 0 && nextX < mapSize && nextY >= 0 && nextY < mapSize && checkNormal[nextX][nextY] == 0){
            if(map[x][y] == map[nextX][nextY]){
                checkNormal[nextX][nextY] = 1;
                searchNormal(nextX, nextY);
            }
        } 
    }
}
void searchUnNormal(int x, int y){
    int nextX, nextY;
    for(int i = 0 ; i < 4 ; i++){
        nextX = x + xCheck[i]; nextY = y + yCheck[i];
        if(nextX >= 0 && nextX < mapSize && nextY >= 0 && nextY < mapSize && checkUnNormal[nextX][nextY] == 0){
            if(map[x][y] == map[nextX][nextY] || map[x][y] == (map[nextX][nextY] -1) || map[x][y] == (map[nextX][nextY] + 1)){
                checkUnNormal[nextX][nextY] = 1;
                searchUnNormal(nextX, nextY);
            }
        } 
    }
}
void bfs(){
    for(int i = 0 ; i < mapSize ; i++){
        for(int j = 0 ; j < mapSize ; j++){
            if(checkNormal[i][j] == 0){
                cntNormal++;
                checkNormal[i][j] = 1;
                searchNormal(i,j);
            }
            if(checkUnNormal[i][j] == 0){
                cntUnNormal++;
                checkUnNormal[i][j] = 1;
                searchUnNormal(i, j);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> mapSize;
    string temp;
    for(int i = 0 ; i < mapSize ; i++){
        cin >> temp;
        for(int j = 0 ; j < mapSize ; j++){
            if(temp[j] == 'R') map[i][j] =  1;
            else if(temp[j] == 'G') map[i][j] = 2;
            else map[i][j] = -1;
        }
    }
    bfs();
    cout << cntNormal << " " << cntUnNormal << "\n";
}