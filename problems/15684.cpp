#include <iostream>
#include <vector>

using namespace std;

int minLadder = -1;
int ladder;
int X, Y;
int map[31][11] = {0, };

bool check(){
    for(int i = 1 ; i <= X ; i++){
        int nx = i;
        for(int j = 1 ; j <= Y ; j++){
            if(map[j][nx] == 1) nx = nx + 1;
            else if(nx-1 >= 1 && map[j][nx-1]) nx = nx - 1;
        }
        if(nx != i) return false;
    }
    return true;
}

void dfs(int y, int cnt){
    if(minLadder != -1) return;
    if(cnt == ladder){
        if(check()) minLadder = cnt;
        return;
    }
    else{
        for(int ny = y; ny <= Y ; ny++){
            for(int nx = 1 ; nx < X ; nx++){
                if(map[ny][nx+1] || map[ny][nx-1] || map[ny][nx]) continue;
                map[ny][nx] = 1;
                dfs(ny, cnt+1);
                map[ny][nx] = 0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int ladderNum;
    cin >> X >> ladderNum >> Y;
    int tempX, tempY;
    for(int i = 0 ; i < ladderNum ; i++){
        cin >> tempY >> tempX;
        map[tempY][tempX] = 1;
    }

    for(int i = 0 ; i <= 3 ; i++){
        ladder = i;
        dfs(1,0);
        if(minLadder != -1) break;
    }
    cout << minLadder << "\n";
}