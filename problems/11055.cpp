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
        dp[i] = a[i];
    }
    int ans = -1;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(a[i] > a[j]) dp[i] = max(dp[j] + a[i], dp[i]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}