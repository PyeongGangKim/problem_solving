#include <iostream>

using namespace std;
long long dp[31];
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    int N;
    cin >> N;
    dp[0]= 1;
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    for(int i = 4 ; i <= N ; i+=2){
        dp[i] = dp[i-2] * dp[2];
        for(int j = i -4; j >= 0 ; j -= 2)dp[i] += 2* dp[j];
    }
    cout << dp[N] << "\n";

}