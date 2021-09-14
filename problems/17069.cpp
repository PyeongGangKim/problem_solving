#include <iostream>
#include <cstring>
typedef long long ll;

using namespace std;

ll cache[33][33][3];
int map[33][33];
int N;
// 0 가로 방향, 1 세로방향, 2 대각선방향

ll dp(int x, int y, int dir){
    // cout << x << " " << y << "\n";
    if(x==N && y == N) return 1;
    ll &res = cache[x][y][dir];
    if(res != -1) return res;
    res = 0;
    
    if(dir == 0 || dir == 2){ // 가로로만 움직이기
        if(y+1 <= N && !map[x][y+1]) res += dp(x,y+1,0);
    }
    if(dir == 1 || dir == 2){ // 세로로만 움직이기
        if(x+1 <= N && !map[x+1][y]) res += dp(x+1, y,1);
    }
    if(x+1 <= N && y+1 <= N && !map[x+1][y] && !map[x][y+1] && !map[x+1][y+1]) res += dp(x+1, y+1,2);
    
    // cout << x << " " << y << " " << res <<"\n";
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            cin >> map[i][j];
        }
    }
    cout << dp(1,2,0) << "\n";
}