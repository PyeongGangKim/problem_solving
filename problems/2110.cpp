#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N,C;
int minN, maxN;
vector<int> nums;
bool check(int mid){
    int cnt = 1;
    int cur = minN;
    for(int i = 1 ; i <= N ; i++){
        if(nums[i] - cur >= mid){
            cnt++;
            cur = nums[i];
        }
    }
    return C <= cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    for(int i = 0 ; i < N ; i++){
        int n;
        cin >> n;
        nums.push_back(n);
    }

    sort(nums.begin(), nums.end());

    minN = nums[0]; maxN = nums[N - 1];
    int low = 1; int high = maxN;
    int mid;
    int res = 0;
    while(low <= high){
        mid = (low + high) / 2;
        if(check(mid)){
            low = mid + 1;
            res = mid;
        }
        else high = mid - 1;
    }
    cout << res << "\n";
}