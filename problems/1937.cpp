#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int map[501][501];
int cache[501][501];
int n;
int xMove[4] = {0,0,1,-1};
int yMove[4] = {1,-1,0,0};
int dp(int y, int x){
    int& res = cache[y][x];
    if(res != -1) return res;
    res = 1;
    for(int i = 0 ; i < 4 ; i++){
        int nextX = x + xMove[i]; int nextY = y + yMove[i];
        if(nextX >= n || nextX < 0 || nextY >= n || nextY < 0 || map[y][x] >= map[nextY][nextX]) continue;
        res = max(res, dp(nextY, nextX) + 1);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
        }
    }
    int result = -1;
    memset(cache, -1, sizeof(cache));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            result = max(result, dp(i,j));
        }
    }
    cout << result << "\n";
}