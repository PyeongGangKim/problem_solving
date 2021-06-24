#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int num[100001];
    int dp[100001];
    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> num[i];
    }
    dp[0] = num[0];
    int result = dp[0];
    for(int i = 1 ; i < N ; i++){
        dp[i] = max(dp[i-1] +  num[i], num[i]);
        result = max(result, dp[i]);
    }
    cout << result << "\n";
}