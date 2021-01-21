#include <iostream>
#include <queue>

using namespace std;

typedef struct Node{
    int x;
    int y;
    int z;
    int num;
}node;
queue<node> q;
int M, N, H;
int box[100][100][100] = {0, };
int maxTime = 0;
int xCheck[6] = {0,0,1,0,-1,0};
int yCheck[6] = {0,0,0,1,0,-1};
int zCheck[6] = {1,-1,0,0,0,0};

bool check(){
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < M ; k++){
                if(box[i][j][k] == 0) return false;
            }
        }
    }
    return true;
}
void bfs(){
    node temp, newNode;
    int x, y, z;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        for(int i = 0 ; i < 6 ; i++){
            x = temp.x + xCheck[i]; y = temp.y + yCheck[i]; z = temp.z + zCheck[i];
            if(x >= 0 && x < M && y >= 0 && y < N && z >= 0 && z < H && box[z][y][x] == 0){
                newNode.x = x; newNode.y = y; newNode.z = z; newNode.num = temp.num + 1;
                box[z][y][x] = 1;
                if(maxTime < newNode.num) maxTime = newNode.num;
                q.push(newNode);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    node temp;

    cin >> M >> N >> H;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < M ; k++){
                cin >> box[i][j][k];
                if(box[i][j][k] == 1){
                    temp.x = k; temp.y = j; temp.z = i; temp.num = 0;
                    q.push(temp);
                }
            }
        }
    }
    bfs();
    if(check()) cout << maxTime << "\n";
    else cout << -1 << "\n";
    
}