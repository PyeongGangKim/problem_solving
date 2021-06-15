#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int testcase;
    cin >> testcase;
    int dp[12];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    //점화식 : f(n) = f(n-3) + f(n-2) + f(n-1)
    for(int i = 4 ; i < 11 ; i++){
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }
    while(testcase--){
        int num;
        cin >> num;
        cout << dp[num] << "\n";
    }
    
}