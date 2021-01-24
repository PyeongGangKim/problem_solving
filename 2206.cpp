#include <iostream>
#include <queue>

using namespace std;

typedef struct Node{
    int x;
    int y;
    int num;
    int wallPass;
}node;

int map[1000][1000];
int N, M;
queue<node> q;

int xCheck[4] = {-1,0,0,1};
int yCheck[4] = {0,-1,1,0};
int minPath;

bool bfs(){
    node temp, newNode;
    int x, y;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            x = temp.x + xCheck[i]; y = temp.y + yCheck[i];
            if(x >= 0 && x < M && y >= 0 && y < N && map[y][x] != 2){
                if(temp.wallPass == 1 && map[y][x] == 1) continue; // 벽을 뚫었던 적 있었는 지 체크.
                if(x == M - 1 && y == N - 1){ // 만약 끝에 도착했다면 나가기.
                    minPath = temp.num + 1;
                    return true;
                }
                if(map[y][x] == 1) newNode.wallPass = 1; // 만약 벽이고, 벽을 뚫었던 적이 없다면 벽뚫기.
                else newNode.wallPass = temp.wallPass; 
                map[y][x] = 2; // map[y][x]를 체크한 것을 2로
                cout << "x: " << x << " y: " << y << " num: " << temp.num + 1 << " wallPass: " << newNode.wallPass << "\n";
                newNode.x = x; newNode.y = y; newNode.num = temp.num + 1;
                q.push(newNode);
            }
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string temp;
    node startNode;
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        for(int j = 0 ; j < M ; j++){
            map[i][j] = temp[j] - '0';
        }
    }
    startNode.x = 0; startNode.y = 0; startNode.num = 1; startNode.wallPass = 0;
    map[0][0] = 2;
    q.push(startNode);
    if(bfs()) cout << minPath << "\n";
    else cout << "-1" << "\n";
}