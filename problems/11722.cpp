#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    int dp[1001];
    int a[1001];

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        dp[i] = 1;
    }
    int ans = -1;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(a[i] < a[j]) dp[i] = max(dp[j] + 1, dp[i]); 
        }
        ans = max(dp[i], ans);
    }
    cout << ans << "\n";
}