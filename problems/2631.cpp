#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N;
    int nums[201];
    int dp[201];
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> nums[i];
    }
    int maxNum = -1;
    for(int i = 0 ; i < N ; i++){
        dp[i] = 1;
        for(int j = i - 1 ; j >= 0 ; j--){
            if(nums[j] < nums[i]) 
            {
                dp[i] = max(dp[i] , dp[j] + 1);
            }
        }
        maxNum = max(maxNum, dp[i]);
    }
    cout << N - maxNum << "\n";
}
