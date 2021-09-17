#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> nums;
    ll cur = 0;
    for(int i = 0 ; i < N ; i++){
        int num;
        cin >> num;
        nums.push_back(num);
        cur += num;
    }
    sort(nums.begin(), nums.end());
    ll res = 0;
    for(int i = 0 ; i < N ; i++){
        res += nums[i] * (cur - nums[i]);
        cur -= nums[i];
    }
    cout << res << "\n";
}