#include <iostream>

using namespace std;

int N,M;
int nums[100001];
bool check(int mid){
    int sum = 0;
    int cnt = 1;
    for(int i = 0 ; i < N ; i++){
        if(nums[i] > mid) return false;
        sum += nums[i];
        if(sum > mid){
            sum = nums[i];
            cnt++;
        }
    }
    return M >= cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int sum = 0;
    for(int i = 0 ; i < N ; i++){
        cin >> nums[i];
        sum += nums[i];
    }

    int low = 1;
    int high = sum;
    int res = 0;
    int mid;
    while(low <= high){
        mid = (low + high)/2;
        if(check(mid)){
            high = mid - 1;
            res = mid;
        }
        else low = mid + 1;
    }

    cout << res << "\n";
}