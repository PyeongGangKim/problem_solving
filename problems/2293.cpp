#include <iostream>
#include <cstring>

using namespace std;
int dp[10001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int n,k;
    cin >> n >> k;
    int coin[n];
    for(int i = 0 ; i < n ; i++){
        cin >> coin[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0 ; i < n ; i++){
        for(int j = coin[i] ; j <= k ; j++){
            dp[j] = dp[j] + dp[j-coin[i]];
        }
    }
    cout << dp[k] << "\n";

}