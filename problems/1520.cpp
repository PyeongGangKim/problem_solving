#include <iostream>
#include <cstring>

using namespace std;

int map[501][501];
int cache[501][501];
int M, N;
int xMove[4] = {0,0,1,-1};
int yMove[4] = {-1,1,0,0};
int dp(int i, int j){
    if(i == M - 1 && j == N - 1) return 1;
    int& res = cache[i][j];
    if(res != -1) return res;
    res = 0;
    for(int k = 0 ; k < 4 ; k++){
        int nextI = i + yMove[k]; int nextJ = j + xMove[k];
        if(nextI < 0 || nextJ < 0 || nextI >= M || nextJ >= N ) continue;
        if(map[i][j] <= map[nextI][nextJ]) continue;
        res += dp(nextI, nextJ);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> map[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    cout << dp(0,0) << "\n";
}