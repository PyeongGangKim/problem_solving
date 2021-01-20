#include <iostream>
#include <queue>

using namespace std;

int N,M;
int map[1001][1001];
typedef struct Node{
    int x;
    int y;
    int num;
}node;

queue<node> q;

int xCheck[4] = {-1,0,0,1};
int yCheck[4] = {0,-1,1,0};

int maxDay = 0;

void bfs(){
    node temp;
    int x,y;
    node newNode;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            x = temp.x + xCheck[i];
            y = temp.y + yCheck[i];
            if(x >= 0 && y >= 0 && x < N && y < M){
                if(map[x][y] == 0){
                    map[x][y] = 1;
                    newNode.x = x;
                    newNode.y = y;
                    newNode.num = temp.num + 1;
                    if(maxDay < newNode.num) maxDay = newNode.num;
                    q.push(newNode);
                }
            }
        }
    }
}
bool check(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(map[i][j] == 0) return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> M >> N;
    node temp;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                temp.x = i;
                temp.y = j;
                temp.num = 0;
                q.push(temp);
            }
        }
    }
    bfs();
    if(check()) cout << maxDay << "\n";
    else cout << "-1" << "\n";
}