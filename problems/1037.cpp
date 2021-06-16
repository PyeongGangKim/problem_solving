#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N;
    cin >> N;
    int nums[51];
    for(int i = 0 ; i < N ; i++){
        cin >> nums[i];
    }
    sort(nums, nums + N);
    cout << nums[0] * nums[N-1] << "\n";

}