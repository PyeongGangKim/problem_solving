#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int map[16][16];
int checkingMap[16][16];

int X, Y;



int killedEnemy = 0;
int maxKilled = -1;

typedef struct Node{
    int x;
    int y;
    int num;
}node;

queue<node> q;
int maxDist;
int xCheck[4] = {-1,0,0,1};
int yCheck[4] = {0,-1,1,0};

void movingEnemy(){
    for(int i = Y - 1 ; i > 0 ; i--){
        for(int j = X - 1 ; j > 0 ; j--){
    
        }
    }
}
void checkMap(){
    killedEnemy = 0;
    while(!q.empty()){
        node tempNode, newNode;
        tempNode = q.front();
        if(tempNode.num == maxDist) continue;
        cout << "x: "<< tempNode.x << " " << "y: "<< tempNode.y << " "<< tempNode.num << "\n";
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nx = tempNode.x + xCheck[i]; int ny = tempNode.y + yCheck[i];
            cout << "nx: "<< nx << " " << "ny: "<< ny << " i: "<< i <<" "<< tempNode.num << "\n";
            if(nx < 0 || ny < 0 || nx > X || ny > Y) continue;
            if(checkingMap[ny][nx] == 2) continue;
            if(checkingMap[ny][nx] == 1) {
                checkingMap[ny][nx] = 0;
                killedEnemy++;
            }
            
            //cout << killedEnemy << "\n";
            newNode.x = nx;
            newNode.y = ny;  
            newNode.num = tempNode.num + 1;
            q.push(newNode);
        }
    }
    maxKilled = max(maxKilled, killedEnemy);
}

void BFS(){
    memcpy(checkingMap, map, sizeof(map));
    for(int i = 0 ; i <= Y ; i++){
        for(int j = 0 ; j <= X ; j++){
            node tempNode;
            if(map[i][j] == 2){
                tempNode.x = j;
                tempNode.y = i;
                tempNode.num = 0;
                q.push(tempNode);
                //cout << "i: " << i << " j: " << j << "\n";
            }
            //cout << "x: "<< tempNode.x << " " << "y: "<< tempNode.y << " "<< tempNode.num << "\n";
            cout << checkingMap[i][j] << " ";
        }
        cout << "\n";
    }
    
    checkMap();
}
void combination(int cnt, int x, int y){
    if(cnt == 3){
        BFS();
    }
    else{
        for(int i = y ; i <= Y ; i++){
            for(int j = x ; j <= X ; j++){
                if(map[i][j] == 1 || map[i][j] == 2) continue;
                cout << i << " " << j << "\n";
                map[i][j] = 2;
                combination(cnt + 1, j, i);
                map[i][j] = 0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> Y >> X >> maxDist;
    for(int i = 0 ; i < Y ; i++){
        for(int j = 0 ; j < X ; j++){
            cin >> map[i][j];
        }
    }
    combination(0,0,0);
    cout << maxKilled << "\n";
}