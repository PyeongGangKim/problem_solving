#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;
ll N, L, R, X;
vector<ll> nums;
bool check[16];
ll res = 0;


void dfs(ll maxNum, ll minNum, ll sum, ll k, ll cnt){
    if(cnt == 0){
        if(maxNum - minNum >= X && sum >= L && sum <= R){
            res++;
        }
    }
    else{
        for(ll i = k ; i < nums.size() ; i++){
            if(check[i]) continue;
            if(sum + nums[i] > R) continue;
            check[i] = true;
            dfs(max(maxNum, nums[i]), min(minNum, nums[i]), sum + nums[i], i+1, cnt - 1);
            check[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R >> X;
    memset(check, false, sizeof(check));
    ll num;
    for(ll i = 0 ; i < N ; i++){
        cin >> num;
        nums.push_back(num);
    }
    
    for(int i = 2 ; i <= N ; i++){
        dfs(0, 1e9, 0, 0, i);
    }
    
    
    cout << res << "\n";

}