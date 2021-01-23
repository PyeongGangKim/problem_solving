#include <iostream>
#include <queue>

using namespace std;

typedef struct Node{
    int x;
    int y;
    int num;
}node;

int mapSize;
int map[301][301];

node start, finish;

queue<node> q;
int xCheck[8] = {2, -2, -2, 2, 1, -1, 1, -1};
int yCheck[8] = {1, -1, 1, -1, 2, -2, -2, 2};



int bfs(){
    node temp, newNode;
    int x, y;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp.x == finish.x && temp.y == finish.y) break;
        for(int i = 0 ; i < 8 ; i++){
            x = temp.x + xCheck[i]; y = temp.y + yCheck[i];
            if(x >= 0 && x < mapSize && y >= 0 && y < mapSize && map[x][y] == 0){
                map[x][y] = 1;
                newNode.x = x; newNode.y = y; newNode.num = temp.num + 1;
                q.push(newNode);
            }
        }
    }
    return temp.num;
}
void initializeMap(){
    for(int i = 0 ; i < mapSize ; i++){
        for(int j = 0 ; j < mapSize ; j++){
            map[i][j] = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int testcase;

    cin >> testcase;
    
    for(int i = 0 ; i < testcase ; i++){
        cin >> mapSize;
        cin >> start.x >> start.y;
        cin >> finish.x >> finish.y;
        initializeMap();
        start.num = 0;
        map[start.x][start.y] = 1;
        q.push(start);
        cout << bfs() << "\n";
    }
}