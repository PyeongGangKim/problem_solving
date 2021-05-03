#include <iostream>
#include <cstring>

using namespace std;

long long cache[101][30];
int nums[101];
int num;
long long dp(int idx, int curNum){
    if(curNum < 0 || curNum > 20) return 0;
    if(idx == num - 2){
        if(curNum == nums[num-1]) return 1;
        else return 0;
    }
    long long& res = cache[idx][curNum];
    if(res != -1) return res;
    res = 0;
    res += dp(idx + 1, curNum + nums[idx+1]);
    res += dp(idx + 1, curNum - nums[idx+1]);
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> num;
    
    for(int i = 0 ; i < num ; i++){
        cin >> nums[i];
    }
    memset(cache, -1, sizeof(cache));
    
    cout << dp(0,nums[0]) << "\n";
    
}