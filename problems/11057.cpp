#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int num;
    int dp[1001][10];
    cin >> num;

    for(int i = 0 ; i <= 9 ; i++){
        dp[1][i] = 1;
    }
    
    for(int i = 2 ; i <= num ; i++){
        for(int j = 0 ; j <= 9 ; j++){
            for(int k = j ; k <= 9 ; k++){
                dp[i][k] += dp[i-1][j];
                dp[i][k] %= 10007;
            }
            
        }
    }
    int sum = 0;
    for(int i = 0 ; i <= 9 ; i++){
        sum += dp[num][i];
    }
    cout << sum % 10007 << "\n";
}