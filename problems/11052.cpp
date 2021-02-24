#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int num;
    cin >> num;
    int value[10001];
    for(int i = 1 ; i <= num ; i++){
        int temp;
        cin >> temp;
        value[i] = temp;
    }
    int dp[10001] = {-1, };
    dp[0] = 0; dp[1] = value[1];
    for(int i = 2 ; i <= num ; i++){
        for(int j = 1 ; j <= i ; j++){
            dp[i] = max(dp[i], dp[i-j] + value[j]); 
        }
    }
    cout << dp[num] << "\n";
}