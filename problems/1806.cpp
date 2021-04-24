#include <iostream>
#include <algorithm>

using namespace std;
int N, S;
int nums[100001];
int MAX = 987654321;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;

    for(int i = 0 ; i < N ; i++){
        cin >> nums[i];
    }
    int left = 0;
    int right = 0;
    int result = MAX;
    int sum = nums[left];
    while(left <= right){
        if(right == N) break;
        if(sum >= S){
            result = min(result, right - left + 1);
            sum -= nums[left];
            left += 1;
            
        }
        else{
            right += 1;
            sum += nums[right];
            
        }
        
    }
    if(result == MAX) cout << "0" << "\n";
    else cout << result << "\n";
}