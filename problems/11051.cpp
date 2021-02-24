#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,k;
    int dp[1001][1001] = {0,};
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= i ; j++){
            if(i==j || j == 0){
                dp[i][j] = 1;
                continue;
            }
            if(i == n && j == k+1) break;
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }
    cout << dp[n][k] << "\n";
}