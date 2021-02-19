#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    long long num;
    cin >> num;

    long long dp[1000001];
    dp[1] = 1;
    dp[2] = 2;

    for(long long i = 3 ; i <= num ; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }
    cout << dp[num] << "\n";
}