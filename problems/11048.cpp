#include <iostream>
#include <cstring>

using namespace std;
int N, M;
int map[1001][1001];
int cache[1001][1001];

int mX[] = {0,1};
int mY[] = {1,0};

int dp(int x, int y){
    if(x == N && y == M) return map[x][y];
    int& res = cache[x][y];

    if(res != -1) return res;
    res = 0;
    for(int i = 0 ; i < 2 ; i++){
        int nX = x + mX[i] ; int nY = y + mY[i];
        if(nX > N || nY > M) continue;

        res = max(dp(nX,nY) + map[x][y], res);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            cin >> map[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    cout << dp(1,1) << "\n";
}