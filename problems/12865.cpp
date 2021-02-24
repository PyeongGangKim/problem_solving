#include <iostream>
#include <algorithm>

using namespace std;
int dp[101][100001] = {0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    
    int w[101], v[101];

    int N, K;
    cin >> N >> K;
    for(int i = 1 ; i <= N ; i++){
        cin >> w[i] >> v[i];
    }

    for(int i = 1 ; i <= N ; i++){
        for(int j = 0 ; j <= K ; j++){
            dp[i][j] = dp[i-1][j];
            if(j - w[i] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }
    cout << dp[N][K] << "\n";
}