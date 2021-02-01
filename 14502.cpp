#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[8][8] = {0, };
int check[8][8] = {0, } ;
int X, Y;
int maxSize = -1;
queue<pair<int,int> > q;
int xCheck[4] = {-1,0,0,1};
int yCheck[4] = {0,-1,1,0};

void checkSafety(){
    int tempSize = 0 ;
    for(int i = 0 ; i < Y ; i++){
        for(int j = 0 ; j < X ; j++){
            if(map[i][j] == 0 && check[i][j] == 0) tempSize++;
            else if(check[i][j] == 2) check[i][j] = 0;
            
        }
    }
    maxSize = max(tempSize, maxSize);
}
void search(){
    while(!q.empty()){
        int y = q.front().first; int x = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nX = x + xCheck[i]; int nY = y + yCheck[i];
            if(nX < 0 || nY < 0 || nX >= X || nY >= Y) continue;
            if(check[nY][nX] != 0 || map[nY][nX] != 0) continue;
            check[nY][nX] = 2;
            q.push(make_pair(nY,nX));
        }
    }
}
void BFS(){
    for(int i = 0 ; i < Y ; i++){
        for(int j = 0 ; j < X ; j++){
            if(map[i][j] == 2) q.push(make_pair(i,j));
        }
    }
    search();
    checkSafety();
}

void combination(int cnt, int num){
    if(cnt == 3){
        BFS();
    }
    else{
        for(int i = 0 ; i < X*Y ; i++){
            int x = i % X; int y = i / X;
            if(map[y][x] != 0 || check[y][x] != 0) continue;
            check[y][x] = 1;
            combination(cnt + 1, i);
            check[y][x] = 0;
        }

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
    combination(0, 0);
    cout << maxSize << "\n";
}