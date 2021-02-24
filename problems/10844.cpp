#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int num;

    cin >> num;
    long long dp[101][11];
    dp[1][0] = 0;
    for(int i = 1 ; i <= 9 ; i++){
        dp[1][i] = 1; 
    }
    for(int i = 2 ; i <= num ; i++){
        dp[i][10] = 0; dp[i][0] = dp[i-1][1];
        for(int j = 1 ; j <= 9 ; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1] % 1000000000;
        }
    }
    long long sum = 0;
    for(int i = 0 ; i <= 9 ; i++){
        sum += dp[num][i] ;
    }
    cout << sum % 1000000000 << "\n";
}