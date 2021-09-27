#include <iostream>
#include <cstring>

#define MAX 7
#define INF 987654321
using namespace std;

int cache[4][MAX][MAX];
int moveN[3] = {1,1,1};
int moveM[3] = {-1,0,1};
int N,M;
int map[MAX][MAX];

int dp(int prev, int n, int m){
    if(N-1 == n) return map[n][m];
    int &res = cache[prev][n][m];
    if(res != -1) return res;
    res = INF;
    for(int i = 0 ; i < 3 ; i++){
        if(i == prev) continue;
        int nextN = n + moveN[i]; int nextM = m + moveM[i];
        if(nextM < 0 || nextM >= M) continue;
        res = min(res, map[n][m] + dp(i, nextN, nextM));
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(cache, -1, sizeof(cache));

    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> map[i][j];
        }
    }
    int res = INF;
    for(int i = 0 ; i < M ; i++){
        res = min(res, dp(3,0,i));
    }
    cout << res << "\n";
}