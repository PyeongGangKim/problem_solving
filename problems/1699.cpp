#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int num;
    int dp[100001];
    cin >> num;

    for(int i = 1 ; i <= num ; i++){
        dp[i] = i;
    }
    for(int i = 2 ; i <= num ; i++){
        for(int j = 2 ; j*j <= i ; j++ ){
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    cout << dp[num] << '\n';
}