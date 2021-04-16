#include <iostream>
#include <cstring>

using namespace std;
int N, M, K;
int cache[226];
int dp[16][16];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M >> K;
    int cnt = 0;
    
    int mid_x, mid_y;
    memset(cache,-1,sizeof(cache));
    memset(dp,0,sizeof(dp));
    dp[1][1] = 1;
    for(int i = 1; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            cnt++;
            if(cnt == K){
                mid_y = i; mid_x = j;
            }
            if(i == 1 && j == 1) continue;
            // dp[i][j] = dp[i-1][j] + dp[i][j-1];
            if(i-1 >= 1) dp[i][j] += dp[i-1][j];
            if(j-1 >= 1) dp[i][j] += dp[i][j-1];
        }
    }
    if(K == 0)cout << dp[N][M] << "\n";
    else{
        int mid_result = dp[mid_y][mid_x];
        dp[mid_y][mid_x] = 1;
        for(int i = mid_y ; i <= N ; i++){
            for(int j = mid_x ; j <= M ; j++){
                if(i == mid_y && j == mid_x)continue;
                dp[i][j] = 0;
                if(i > mid_y) dp[i][j] += dp[i-1][j];
                if(j > mid_x) dp[i][j] += dp[i][j-1];
            }
        }
        cout << mid_result * dp[N][M] << "\n";
    }
}