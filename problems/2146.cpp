#include <iostream>
#include <queue>
#include <cstring>
#define MAX 101

using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];
int N;

int moveX[4] = {0,0,1,-1};
int moveY[4] = {1,-1,0,0};
int res = 1e9;

void changeBfs(int x, int y, int num){
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));

    while(!q.empty()){
        int curX = q.front().first; int curY = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nextX = curX + moveX[i] ; int nextY = curY + moveY[i];
            if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= N || map[nextX][nextY] != 1) continue; //map[curX][curY]가 1이 아니면 continue 그리고 curX < 0 or curX >= N
            map[nextX][nextY] = num;
            q.push(make_pair(nextX,nextY));
        }
    }
}
void bfs(int x, int y, int num){
    queue<pair<int, pair<int,int> > > q;
    q.push(make_pair(0,make_pair(x,y)));

    while(!q.empty()){
        int cnt = q.front().first;
        int curX = q.front().second.first; int curY = q.front().second.second;
        q.pop();
        if(map[curX][curY] != num && map[curX][curY] != 0){   
            res = min(res,cnt - 1);
            visited[curX][curY] = true;
            break;
        }
        for(int i = 0 ; i < 4 ; i++){
            int nextX = curX + moveX[i] ; int nextY = curY + moveY[i];
            if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) continue;
            if(visited[nextX][nextY]) continue;
            visited[nextX][nextY] = true;
            if(map[nextX][nextY] == num){
                q.push(make_pair(cnt,make_pair(nextX,nextY)));
            }
            else{
                q.push(make_pair(cnt+1,make_pair(nextX,nextY)));
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> map[i][j];
        }
    }
    int num = 1;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(map[i][j] == 1){
                num++;
                map[i][j] = num;
                changeBfs(i,j,num);
            }
        }
        
    }
    num = 2;
    memset(visited,false,sizeof(visited));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cout << map[i][j] << " ";
            if(map[i][j] == num){
                visited[i][j] = true;
                bfs(i,j,num);
                memset(visited,false,sizeof(visited));
                num++;
            }
            
        }
        cout << "\n";
    }
    cout << res << "\n";

}