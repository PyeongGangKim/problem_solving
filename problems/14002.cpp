#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    vector<int> cache[1001];
    int dp[1001];
    int a[1001];

    int n;

    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        dp[i] = 1;
        cache[i].push_back(a[i]);
    }
    int ans = 1;
    int ans_num;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(a[i] > a[j]){
                if(dp[i] < dp[j] + 1){
                    cache[i].clear();
                    cache[i] = cache[j];
                    cache[i].push_back(a[i]);
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if(ans < dp[i]){
            ans = dp[i];
            ans_num = i;
        }
    }
    cout << ans << "\n";
    for(int i = 0 ; i < cache[ans_num].size() ; i++){
        cout << cache[ans_num][i] << " ";
    }
    
}
