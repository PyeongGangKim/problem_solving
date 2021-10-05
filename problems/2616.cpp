#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int sums[50001];
int nums[50001];
int cache[50001][3];
int N;
int seqNum;

int dp(int i, int cnt){
    if(i > N || cnt == 3) return 0;
    int &res = cache[i][cnt];
    if(res != -1) return res;
    
    res = 0;
    if(i + seqNum - 1 <= N){//현재꺼부터 seqNum만큼 추가하는 경우
        res = dp(i+seqNum, cnt+1) + sums[i+seqNum-1] - sums[i-1]; 
    }
    
    res = max(res,dp(i+1, cnt));// 추가하지 않는 경우
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        cin >> nums[i];
        sums[i] = sums[i-1] + nums[i];
    }
    cin >> seqNum;
    memset(cache, -1, sizeof(cache));

    cout << dp(1,0) << "\n";

    
}