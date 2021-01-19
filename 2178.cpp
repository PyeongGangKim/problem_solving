#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N,M;
int map[101][101];
int check[101][101];

typedef struct Node{
    int x;
    int y;
    int num;
}node;

queue<node> q;
int xCheck[4] = {-1,0,0,1};
int yCheck[4] = {0,-1,1,0};
int minPath;

void bfs(){
    int x,y;
    node temp;
    node newNode;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            x = temp.x + xCheck[i];
            y = temp.y + yCheck[i];
            if(x >= 0 && y >= 0 && x < N && y < M){
                if(check[x][y] == 0 && map[x][y] == 1){
                    if(x == N - 1 && y == M - 1){
                        minPath = temp.num+1;
                    }
                    newNode.x = x;
                    newNode.y = y;
                    newNode.num = temp.num+1;
                    check[x][y] = 1;
                    q.push(newNode);
                }
            }
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string str;
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        cin >> str;
        for(int j = 0 ; j < M ; j++){
            map[i][j] = str[j] - '0';
        }
    }
    node temp;
    temp.x = 0 ;
    temp.y = 0;
    temp.num = 1;
    check[0][0] = 1;
    q.push(temp);
    bfs();
    cout << minPath << "\n";

}