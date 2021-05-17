#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
int map[64][64];
int check[64][64];
int moveX[2] = {0,1};
int moveY[2] = {1,0};

bool bfs(){
    queue<pair<int,int> > q;
    check[0][0] = true;

    q.push(make_pair(0,0));

    while(!q.empty()){
        int x = q.front().first; int y = q.front().second;
        q.pop();
        if(map[y][x] == -1) return true;
        for(int i = 0 ; i < 2 ; i++){
            int nextX = x + moveX[i]*map[y][x]; int nextY = y + moveY[i]*map[y][x];
            if(nextX >= N || nextY >= N || check[nextY][nextX]) continue;
            check[nextY][nextX] = true;
            q.push(make_pair(nextX,nextY));
            
        }
    }
    return false;
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

    memset(check, false, sizeof(check));
    if(bfs()) cout << "HaruHaru\n";
    else cout << "Hing\n";
}
