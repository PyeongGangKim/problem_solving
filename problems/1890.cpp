#include <iostream>
#include <cstring>

using namespace std;
int N;
int map[101][101];
long long cache[101][101];
long long dp(int x, int y){
    if(x > N-1 || y > N-1) return 0;
    long long &res = cache[x][y];
    if(res != -1) return res;
    if(x == N-1 && y == N-1) return res = 1;
    if(map[x][y] == 0) return res = 0;
    return res = dp(x + map[x][y], y) + dp(x, y + map[x][y]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> map[i][j];
        }
    }
    cout << dp(0, 0) << "\n";
}