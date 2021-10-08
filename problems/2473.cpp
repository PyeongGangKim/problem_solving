#include <iostream>
#include <algorithm>

using namespace std;

#define INF 9999999999
typedef long long ll;
ll nums[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        cin >> nums[i];
    }
    int start = 0;
    int end = N-1;
    ll diff = INF;
    int num1; int num2; int num3;
    int x;
    sort(nums,nums + N);
    for(int i = 0 ; i < N ; i++){
        x = nums[i];
        start = i+1;
        end = N-1;
        
        while(start < end){
            ll sum = x + nums[start] + nums[end];
            if(abs(sum) < abs(diff)){
                diff = sum;
                num1 = x;
                num2 = nums[start];
                num3 = nums[end];
            }
            if(sum < 0) start++;
            else if(sum > 0) end--;
            else{
                i = N;
                break;
            }
        }
    }
    cout << num1 << " " << num2 << " " << num3 << "\n";
}