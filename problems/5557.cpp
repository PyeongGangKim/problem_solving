#include <iostream>
#include <cstring>

using namespace std;

int cache[101];
int nums[101];
int num;
int dp(int idx, int curNum){
    if(idx == num - 2){
        cout << curNum << "\n";
        if(curNum == nums[num-1]) return 1;
    }
    int& res = cache[idx];
    if(res != -1) return res;
    res = 0;
    if(curNum + nums[idx+1] <= 20){
        res += dp(idx+1, curNum + nums[idx+1]);
    }
    if(curNum - nums[idx+1] >= 0){
        res += dp(idx+1, curNum - nums[idx+1]);
    }
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
    dp(0,nums[0]);
    cout << cache[0] << "\n";
    
}