#include <iostream>
#include <cstring>

#define MAX 2001

using namespace std;
int map[MAX][MAX];
bool check[MAX][MAX];
int moveX[4] = {0,0,1,-1};
int moveY[4] = {1,-1,0,0};
void dfs(int x, int y){
    for(int i = 0 ; i < 4 ; i++){
        int nX = x + moveX[i]; int nY = y + moveY[i];
        if(x < 0 || x >= MAX || y < 0 || y >= MAX) continue;
        if(check[nX][nY] || map[nX][nY] == 0) continue;
        check[nX][nY] = true;
        dfs(nX, nY);    
    }
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(check, false, sizeof(check));

    int x1,y1,x2,y2;
    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        x1 = (x1 + 500) * 2;
        y1 = (y1 + 500) * 2;
        x2 = (x2 + 500) * 2;
        y2 = (y2 + 500) * 2;
        for(int i = x1 ; i <= x2 ; i++){
            map[i][y1] = 1;
            map[i][y2] = 1;
        }
        for(int i = y1 ; i <= y2 ; i++){
            map[x1][i] = 1;
            map[x2][i] = 1;
        }
    }
    int cnt = 0;
    for(int i = 0 ; i < MAX ; i++){
        for(int j = 0 ; j < MAX ; j++){
            if(map[i][j] == 1 && !check[i][j]){
                cnt++;
                check[i][j] = true;
                dfs(i,j);
            }
        }
    }
    
    if(check[1000][1000]) cnt--;
    cout << cnt << "\n";
}