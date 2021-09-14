#include <iostream>
#include <cstring>
#include <queue>

#define MAX 1001

using namespace std;

int N, M, H, W, SR, SC, FR, FC;

int map[MAX][MAX];
bool check[MAX][MAX];

int moveX[4] = {0,0,1,-1};
int moveY[4] = {1,-1,0,0};

bool isNoWall(int r, int c, int move){ // 전체를 체크하는 것이 아닌, 하로 움직인거면 가장 아랫줄만 체크, 위로 움진인거면 가장 위쪽, 오른쪽으로 움직인거면 가장 오른쪽, 
    // 1 오, 2 왼, 3 하, 4 상
    if(move == 1){//맨 오른쪽만 체크
        for(int i = r ; i < r+H ; i++){
            for(int j = c+W-1 ; j < c+W ; j++){
                if(map[i][j] == 1) return false;
            }
        }
    }
    else if(move == 2){ // 맨 왼쪽만 체크
        for(int i = r ; i < r+H ; i++){
            for(int j = c ; j < c+1 ; j++){
                if(map[i][j] == 1) return false;
            }
        }
    }
    else if(move == 3){// 맨 아래만 체크
        for(int i = r+H-1 ; i < r+H ; i++){
            for(int j = c ; j < c+W ; j++){
                if(map[i][j] == 1) return false;
            }
        }
        
    }
    else{ // 맨 위쪽만 체크
        for(int i = r ; i < r+1 ; i++){
            for(int j = c ; j < c+W ; j++){
                if(map[i][j] == 1) return false;
            }
        }
    }
    

    return true;
}
int bfs(){
    queue<pair<int, pair<int,int> > > q;
    q.push(make_pair(0, make_pair(SR, SC)));
    while(!q.empty()){
        int num = q.front().first;
        int r = q.front().second.first; int c = q.front().second.second;
        q.pop();
        
        if(r == FR && c == FC)return num;
        for(int i = 0 ; i < 4 ; i++){
            int nextR = r + moveX[i]; int nextC = c + moveY[i];
            if(nextR < 1 || nextR > N-H+1 || nextC < 1 || nextC > M-W+1 || check[nextR][nextC]) continue;//1보다 작거나 N-H+1 보다 크거나 이미 방문한 곳이면 nono
            if(!isNoWall(nextR, nextC, i+1)) continue;
            check[nextR][nextC] = true;
            q.push(make_pair(num + 1, make_pair(nextR, nextC)));
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(check, false, sizeof(check));

    cin >> N >> M;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            cin >> map[i][j];
        }
    }
    cin >> H >> W >> SR >> SC >> FR >> FC;

    cout << bfs() << "\n";
}