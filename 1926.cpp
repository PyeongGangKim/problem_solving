#include <iostream>
#include <queue>

using namespace std;
int map[501][501];
int check[501][501] = {0,};
typedef struct Coordinate{
    int x;
    int y;
}coordinate;

queue<coordinate> q;
int xCheck[4] = {-1,0,0,1};
int yCheck[4] = {0,-1,1,0};
int maxSize = 0;
int cnt = 0;
int N,M;

void bfs(){
    coordinate temp;
    coordinate pushCoordinate;
    int x,y;
    int size = 1;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            x = temp.x + xCheck[i];
            y = temp.y + yCheck[i];
            if(x >= 0 && y  >= 0 && x < N && y < M){
                if(check[x][y] == 0 && map[x][y]){
                    check[x][y] = 1;
                    pushCoordinate.x = x;
                    pushCoordinate.y = y;
                    q.push(pushCoordinate);
                    size++;
                }
            }
        }
    }
    if(maxSize < size) maxSize = size;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> map[i][j];
        }
    }
    coordinate temp;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(map[i][j] == 1 && check[i][j] == 0){
                temp.x = i;
                temp.y = j;
                q.push(temp);
                check[i][j] = 1;
                bfs();
                cnt++;
            }
        }
    }
    cout << cnt << "\n" << maxSize << "\n";
}