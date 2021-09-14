#include <iostream>

#define DIV 1000000009

using namespace std;

int dp[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[1] = 1; dp[2] = 2; dp[3] = 2; dp[4] = 3; dp[5] = 3; dp[6] = 6;
    for(int i = 7 ; i < 100001 ; i++){
        dp[i] = ((dp[i-2] + dp[i-4])%DIV + dp[i-6]) % DIV;
    }
    int N;
    cin >> N;
    int n;
    while(N--){
        cin >> n;
        cout << dp[n] << "\n";
    }
}